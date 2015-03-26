#ifndef __p16f1847__h__
#define __p16f1847__h__

#include "p1xf1xxx.h"

/*
 * PIC16F1847 - Enhanced Midrange Microcontroller with 1K RAM, 8K Flash and 256 bytes of EEPROM
 *
 * The processor is a larger version of the 16f1823 family (implemented in p1xf1xxx.{h,cc})
 */

class P16F1847 : public P12F1822
{
public:
  //Port B with interrupt on change
  PicPortIOCRegister *m_portb;
  PicTrisRegister    *m_trisb;
  PicLatchRegister   *m_latb;

  IOC                *m_iocbp;
  IOC                *m_iocbn;
  IOCxF              *m_iocbf;

  WPU                *m_wpub;
  ANSEL_P            m_anselb;

  virtual unsigned int program_memory_size() const {return 8192;}
  virtual unsigned int register_memory_size() const {return 0x1000;}
  virtual PROCESSOR_TYPE isa() {return _P16F1847_;}

  virtual void create(int ram_top, int eeprom_size);
  virtual void create_iopin_map();
  virtual void create_sfr_map();

   P16F1847(const char *_name=0, const char *desc=0);
  ~P16F1847();

  static Processor *construct(const char *name);

private:
  void create_ports();
};

#endif
#ifndef __p16f1847__h__
#define __p16f1847__h__

#include "p1xf1xxx.h"

/*
 * PIC16F1847 - Enhanced Midrange Microcontroller with 1K RAM, 8K Flash and 256 bytes of EEPROM
 *
 * The processor is a larger version of the 16f1823 family (implemented in p1xf1xxx.{h,cc})
 */

class P16F1847 : public P12F1822
{
public:
  //Port B with interrupt on change
  PicPortIOCRegister *m_portb;
  PicTrisRegister    *m_trisb;
  PicLatchRegister   *m_latb;

  IOC                *m_iocbp;
  IOC                *m_iocbn;
  IOCxF              *m_iocbf;

  WPU                *m_wpub;
  ANSEL_P            m_anselb;

  virtual unsigned int program_memory_size() const {return 8192;}
  virtual unsigned int register_memory_size() const {return 0x1000;}
  virtual PROCESSOR_TYPE isa() {return _P16F1847_;}

  virtual void create(int ram_top, int eeprom_size);
  virtual void create_iopin_map();
  virtual void create_sfr_map();

   P16F1847(const char *_name=0, const char *desc=0);
  ~P16F1847();

  static Processor *construct(const char *name);

private:
  void create_ports();
};

#endif
#ifndef __p16f1847__h__
#define __p16f1847__h__

#include "p1xf1xxx.h"

/*
 * PIC16F1847 - Enhanced Midrange Microcontroller with 1K RAM, 8K Flash and 256 bytes of EEPROM
 *
 * The processor is a larger version of the 16f1823 family (implemented in p1xf1xxx.{h,cc})
 */

class P16F1847 : public P12F1822
{
public:
  PicPortBRegister   *m_portb;
  PicTrisRegister    *m_trisb;
  PicLatchRegister   *m_latb;
  WPU                *m_wpub;
  ANSEL_P            m_anselb;

  virtual unsigned int program_memory_size() const {return 8192;}
  virtual unsigned int register_memory_size() const {return 0x1000;}
  virtual PROCESSOR_TYPE isa() {return _P16F1847_;}

  virtual void create(int ram_top, int eeprom_size);
  virtual void create_iopin_map();
  virtual void create_sfr_map();

   P16F1847(const char *_name=0, const char *desc=0);
  ~P16F1847();

  static Processor *construct(const char *name);

private:
  void create_ports();
};

#endif
