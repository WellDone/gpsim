#include "p16f1847.h"
#include "pic-ioports.h"
#include "packages.h"

Processor * P16F1847::construct(const char *name)
{

  P16F1847 *p = new P16F1847(name);

  p->create(0x3ff, 256);
  p->create_invalid_registers();
  p->create_symbols();
  return p;
}

P16F1847::~P16F1847()
{
  delete_sfr_register(m_portb);
  delete_sfr_register(m_trisb);
  delete_sfr_register(m_latb);
  delete_sfr_register(m_iocbf);
  delete_sfr_register(m_iocbn);
  delete_sfr_register(m_iocbp);

  delete_sfr_register(m_wpub);
  remove_sfr_register(&m_anselb);
}

P16F1847::P16F1847(const char *_name, const char *desc)
  : P12F1822(_name,desc), 
  m_anselb(this, "anselc", "Analog Select port b")
{
  m_iocbp = new IOC(this, "iocbp", "", 0xff);
  m_iocbn = new IOC(this, "iocbn", "", 0xff);
  m_iocbf = new IOCxF(this, "iocbf", "", 0xff);
  m_portb = new PicPortIOCRegister(this, "portb", "", intcon, m_iocbn, m_iocbp, m_iocbf, 8, 0xff);
  m_trisb = new PicTrisRegister(this, "trisb", "", m_portb, false, 0xff);
  m_latb = new PicLatchRegister(this, "latb", "", m_portb, 0xff);
  m_wpub = new WPU(this, "wpub", "Weak Pull-up Register port b", m_portb, 0xff);
}

void  P16F1847::create(int ram_top, int eeprom_size)
{

  create_iopin_map();
  e = new EEPROM_EXTND(this, pir2);
  set_eeprom(e);

  pic_processor::create();

  e->initialize(eeprom_size, 16, 16, 0x8000);
  e->set_intcon(intcon);
  e->get_reg_eecon1()->set_valid_bits(0xff);

  //Add GPR registers for each bank of RAM
  //There are 1024 bytes of GPR, in 12 pages
  //of 80 bytes each + 16 bytes of common ram
  //and 48 bytes in bank 12.  Datasheet page 23
  for (int bank=0; bank<=11; ++bank)
  {
  	int start = 0x20 + (bank*128);
  	int end = start + 80 - 1;

  	add_file_registers(start, end, 0x00);
  }

  //Common RAM and partial BANK12
  add_file_registers(0x70, 0x7F, 0x00);
  add_file_registers(0x620, 0x620 + 48 -1, 0x00);

  //Initialize Special Function Registers
  create_ports();

  _14bit_e_processor::create_sfr_map();
  P12F1822::create_sfr_map();
  create_sfr_map();

  // Set DeviceID (0b010100100 + 5 bits for revision ID for 16F1847)
  if (m_configMemory && m_configMemory->getConfigWord(6))
      m_configMemory->getConfigWord(6)->set(0x1480);
}

void P16F1847::create_sfr_map()
{
  create_ports();

  ssp.set_sckPin(&(*m_portb)[4]);
  ssp.set_sdiPin(&(*m_portb)[1]);
  ssp.set_sdoPin(&(*m_portb)[2]);
  ssp.set_ssPin(&(*m_portb)[5]);
  ssp.set_tris(m_trisb);

  // Pin values for default APFCON
  usart.set_TXpin(&(*m_portb)[2]); // TX pin
  usart.set_RXpin(&(*m_portb)[1]);  // RX pin
}

void P16F1847::create_ports()
{
  /*
   * Configure port B and connect the digital and analog control
   * registers.
   */
  add_sfr_register(m_iocbf, 0x396);
  add_sfr_register(m_iocbn, 0x395);
  add_sfr_register(m_iocbp, 0x394);
  add_sfr_register(m_portb, 0x0D);
  add_sfr_register(m_trisb, 0x8D);
  add_sfr_register(&m_anselb, 0x18D, RegisterValue(0xFE, 0));
  add_sfr_register(m_wpub, 0x20D);

  //All Port B pins are analog except for B0 (AN5-AN11, but not in order)
  m_anselb.config(0xFE, 5);
  m_anselb.setValidBits(0xFE);
  m_anselb.setAdcon1(&adcon1);
  m_anselb.setAnsel(&ansela);
  ansela.setAnsel(&m_anselb);

  adcon1.setIOPin(5, &(*m_portb)[6]);
  adcon1.setIOPin(6, &(*m_portb)[7]);
  adcon1.setIOPin(7, &(*m_portb)[5]);
  adcon1.setIOPin(8, &(*m_portb)[4]);
  adcon1.setIOPin(9, &(*m_portb)[3]);
  adcon1.setIOPin(10, &(*m_portb)[2]);
  adcon1.setIOPin(11, &(*m_portb)[1]);
}

void P16F1847::create_iopin_map()
{
	package = new Package(20);
	if (!package)
		return;

  package->assign_pin(19, m_porta->addPin(new IO_bi_directional_pu("porta0"),0));
  package->assign_pin(20, m_porta->addPin(new IO_bi_directional_pu("porta1"),1));
  package->assign_pin(1, m_porta->addPin(new IO_bi_directional_pu("porta2"),2));
  package->assign_pin(2, m_porta->addPin(new IO_bi_directional_pu("porta3"),3));
  package->assign_pin(3, m_porta->addPin(new IO_bi_directional_pu("porta4"),4));
  package->assign_pin(4, m_porta->addPin(new IO_bi_directional_pu("porta5"),5));
  package->assign_pin(17, m_porta->addPin(new IO_bi_directional_pu("porta6"),6));
  package->assign_pin(18, m_porta->addPin(new IO_bi_directional_pu("porta7"),7));

  package->assign_pin(7, m_portb->addPin(new IO_bi_directional_pu("portb0"),0));
  package->assign_pin(8, m_portb->addPin(new IO_bi_directional_pu("portb1"),1));
  package->assign_pin(9, m_portb->addPin(new IO_bi_directional_pu("portb2"),2));
  package->assign_pin(10, m_portb->addPin(new IO_bi_directional_pu("portb3"),3));
  package->assign_pin(11, m_portb->addPin(new IO_bi_directional_pu("portb4"),4));
  package->assign_pin(12, m_portb->addPin(new IO_bi_directional_pu("portb5"),5));
  package->assign_pin(13, m_portb->addPin(new IO_bi_directional_pu("portb6"),6));
  package->assign_pin(14, m_portb->addPin(new IO_bi_directional_pu("portb7"),7));

  //VDD and VSS
  package->assign_pin(5, 0);
  package->assign_pin(6, 0);
  package->assign_pin(15, 0);
  package->assign_pin(16, 0);
}
