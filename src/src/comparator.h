/*
   Copyright (C) 1998-2002 T. Scott Dattalo
   Copyright (C) 2006,2010,2013 Roy R. Rankin

This file is part of the libgpsim library of gpsim

This library is free software; you can redistribute it and/or
modify it under the terms of the GNU Lesser General Public
License as published by the Free Software Foundation; either
version 2.1 of the License, or (at your option) any later version.

This library is distributed in the hope that it will be useful,
but WITHOUT ANY WARRANTY; without even the implied warranty of
MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the GNU
Lesser General Public License for more details.

You should have received a copy of the GNU Lesser General Public
License along with this library; if not, see 
<http://www.gnu.org/licenses/lgpl-2.1.html>.
*/

#ifndef __COMPARATOR_H__
#define __COMPARATOR_H__

#include "14bit-tmrs.h"

/***************************************************************************
 *
 * Include file for: Processors with dual comparators and Voltage Refarence
 *
 * 
 *
 ***************************************************************************/

#define CFG_MASK 0x7
#define CFG_SHIFT 3

class CMSignalSource;
class VRSignalSource;
class CMCON;
class TMRL;

  enum compare_inputs
   {
	AN0 = 0,
	AN1,
	AN2,
	AN3,
	VREF = 6,	// use reference voltage
	NO_IN = 7	// no input port
   };
  enum compare_outputs
   {
	OUT0 = 0,
	OUT1,
	ZERO = 6,	// register value == 0
	NO_OUT = 7	// no ouput port
   };

class VRCON : public sfr_register
{
 public:

 CMCON *_cmcon;

  enum VRCON_bits
    {
      VR0 = 1<<0,	// VR0-3 Value selection
      VR1 = 1<<1,
      VR2 = 1<<2,
      VR3 = 1<<3,
      VRSS = 1<<4,	// Use external references (16f88x)
      VRR = 1<<5,	// Range select
      VROE = 1<<6,	// Output Reference to external pin 
      VREN = 1<<7	// Enable Vref 
    };

  VRCON(Processor *pCpu, const char *pName, const char *pDesc);
  ~VRCON();

  virtual void put(unsigned int new_value);
  virtual void setIOpin(PinModule *);
  virtual double get_Vref();
  void setValidBits(unsigned int mask) { valid_bits = mask;}
                                                                                
protected:
  unsigned int		valid_bits;
  PinModule 		*vr_PinModule;
  double 		vr_Vref;
  stimulus		*vr_pu;
  stimulus		*vr_pd;
  stimulus		*vr_06v;
  double		vr_Rhigh;
  double		vr_Rlow;
  double		Vref_high;	// usually VDD
  double		Vref_low;	// usually VSS
  char			*pin_name;	// original name of pin

};

// VSCOM class with two comparators as per 16f690
//
class VRCON_2 : public sfr_register
{
 public:

 CMCON *_cmcon;

  enum VRCON_bits
    {
      VR0 = 1<<0,	// VR0-3 Value selection
      VR1 = 1<<1,
      VR2 = 1<<2,
      VR3 = 1<<3,
      VP6EN = 1<<4,	// 0.6V reference enable
      VRR = 1<<5,	// Range select
      C2VREN = 1<<6,	// Comparator 2 Reference enable
      C1VREN = 1<<7	// Comparator 1 Reference enable
    };

  VRCON_2(Processor *pCpu, const char *pName, const char *pDesc);
  ~VRCON_2();

  virtual void put(unsigned int new_value);

protected:
  unsigned int		valid_bits;
  PinModule 		*vr_PinModule;
  double 		vr_Vref;
  stimulus		*vr_pu;
  stimulus		*vr_pd;
  stimulus		*vr_06v;
  char			*pin_name;	// original name of pin

};

class CM_stimulus : public stimulus
{
   public:

	CM_stimulus(CMCON *arg, const char *n=0,
           double _Vth=0.0, double _Zth=1e12
           );
	~CM_stimulus();

    CMCON *_cmcon;

     virtual void   set_nodeVoltage(double v);

};
class CMCON1 : public sfr_register
{
 public:
  enum CMCON1_bits
  {
	CMSYNC = 1<<0,
	T1GSS  = 1<<1
  };

  virtual void put(unsigned int);
  void set_tmrl(TMRL *arg) { m_tmrl = arg; }
  CMCON1(Processor *pCpu, const char *pName, const char *pDesc);
  ~CMCON1();

 private:
  TMRL *m_tmrl;

};

class CMCON : public sfr_register
{
 public:


  VRCON *_vrcon;
  enum CMCON_bits
    {
      CM0 = 1<<0,
      CM1 = 1<<1,
      CM2 = 1<<2,
      CIS = 1<<3,
      C1INV = 1<<4,
      C2INV = 1<<5,
      C1OUT = 1<<6,
      C2OUT = 1<<7,
    };


  virtual void setINpin(int i, PinModule *);
  virtual void setOUTpin(int i, PinModule *);
  virtual void assign_pir_set(PIR_SET *new_pir_set);
  virtual unsigned int get();
  virtual void rename_pins(unsigned int) { cout << "CMCON::rename_pins() should not be called\n";}
  virtual void put(unsigned int);
  virtual void set_configuration(int comp, int mode, int il1, int ih1, int il2, int ih2, int out);
  virtual double comp_voltage(int ind, int invert);

  void releasePin(int);



  void set_tmrl(TMRL *arg) { m_tmrl = arg; }
  void set_eccpas(ECCPAS *_eccpas) { m_eccpas = _eccpas; }
  CMCON(Processor *pCpu, const char *pName, const char *pDesc);
  ~CMCON();

protected:
  PinModule *cm_input[4];
  PinModule *cm_output[2];
  char *cm_input_pin[4];
  char *cm_output_pin[2];
  CMSignalSource *cm_source[2];
  unsigned int m_CMval[2];
  PIR_SET *pir_set;
  TMRL *m_tmrl;
  CM_stimulus *cm_stimulus[4];
  ECCPAS 	*m_eccpas;

  static const int cMaxConfigurations=8;
  static const int cMaxComparators=2;

  unsigned int m_configuration_bits[cMaxComparators][cMaxConfigurations];

};

class ComparatorModule
{
 public:

  ComparatorModule(Processor *);
  void initialize( PIR_SET *pir_set, PinModule *pin_vr0, PinModule *pin_cm0, 
	PinModule *pin_cm1, PinModule *pin_cm2,
	PinModule *pin_cm3, PinModule *pin_cm4, PinModule *pin_cm5);
  //protected:
  CMCON cmcon;
  CMCON1 cmcon1;
  VRCON vrcon;

};

/*
 * Compare module for 16f88x processors
 */

class CM1CON0;
class CM1CON0_2;
class CM2CON0;

/*
 * SRCON SR Latch Control Register
 */
class SRCON  : public sfr_register
{
 public:


  enum SRCON_bits
  {
	FVREN = 1<<0,  // Fixed Voltage Reference Enable
	PULSR = 1<<2,  // Pulse Reset of SR latch
	PULSS = 1<<3,  // Pulse set of SR Latch
	C2REN = 1<<4,  // C2OUT resets SR latch
	C1SEN = 1<<5,  // C1OUT sets SR latch
	SR0   = 1<<6,  // MUX SR Q out and C1OUT
	SR1   = 1<<7   // MUX SR -Q out and C2OUT
  };
  int writable_bits;
  bool SR_Q;
  bool set;
  bool reset;

  virtual void put(unsigned int new_value);

  SRCON(Processor *pCpu, const char *pName, const char *pDesc);
  ~SRCON(){}
};

/*
 * CM2CON1 Comparator control register 1
 */
class CM2CON1 : public sfr_register
{
 public:

  
  enum CM2CON1_bits
  {
	C2SYNC = 1<<0, //C2 Output sync bit
	T1GSS  = 1<<1, // Timer1 Gate Source Select bit
	C2RSEL = 1<<4, // C2 Reference Select bit
	C1RSEL = 1<<5, // C1 Reference Select bit
	MC2OUT = 1<<6, // Mirror C2OUT bit
	MC1OUT = 1<<7  // Mirror C1OUT bit
  };
  int writable_bits;
  CM1CON0 *m_cm1con0;
  CM2CON0 *m_cm2con0;

  virtual void put(unsigned int new_value);
  void link_cm12con0(CM1CON0 *_cm1con0, CM2CON0 *_cm2con0);

  CM2CON1(Processor *pCpu, const char *pName, const char *pDesc);
  ~CM2CON1(){}
};

class CM12SignalSource;
/*
 * CM12CON0 is common support for CM1CON0 AND CM2CON0
 */
class CM12CON0 : public sfr_register
{
 public:


  VRCON *m_vrcon;
  enum CM12CON0_bits
    {
      CH0 = 1<<0,	// Channel select bit 0
      CH1 = 1<<1,	// Channel select bit 1
      R   = 1<<2,	// Reference select bit (non-inverting input)
      POL = 1<<4,	// Output polarity select bit
      OE  = 1<<5,	// Output enable
      OUT = 1<<6,	// Output bit 
      ON  = 1<<7,	// Enable bit
    };


  virtual void put(unsigned int);
  virtual unsigned int get();
  virtual void setpins(PinModule * c12in0, PinModule * c12in1,
	PinModule * c12in2, PinModule * c12in3, PinModule * cinPlus,
	PinModule * cout);
  virtual void state_change(unsigned int cmcon_val) { cout << "CM12CON:state_change should not be called\n"; }
  virtual double CVref() { cout << "CM12CON:CVref should not be called\n"; return(0.);}
 
  virtual void link_registers(PIR_SET *new_pir_set, CM2CON1 *_cm2con1,
	VRCON *_vrcon, SRCON *_srcon, ECCPAS *_eccpas);


  void set_tmrl(TMRL *arg) { m_tmrl = arg; }
  void releasePin();

  CM12CON0(Processor *pCpu, const char *pName, const char *pDesc);
  ~CM12CON0();

protected:
  friend class CM1CON0_2;
  friend class CM1CON0;
  friend class CM2CON1;
  friend class CM2CON0;

  PinModule 	*cm_input[5];
  PinModule 	*cm_output;
  CM12SignalSource *cm_source;
  CM2CON1 	*m_cm2con1;
  SRCON 	*m_srcon;
  PIR_SET 	*pir_set;
  TMRL 		*m_tmrl;
  CM_stimulus 	*cm_stimulus[2];
  Stimulus_Node *cm_snode[2];
  ECCPAS 	*m_eccpas;
  CM_stimulus 	*cm_cvref;
  CM_stimulus 	*cm_v06ref;

};

class CM1CON0 : public CM12CON0
{
 public:
  CM1CON0(Processor *pCpu, const char *pName, const char *pDesc) :
	CM12CON0(pCpu, pName, pDesc) {}
  ~CM1CON0(){}

  virtual void state_change(unsigned int cmcon_val);
  virtual double CVref();

};
class CM2CON0 : public CM12CON0
{
 public:
  CM2CON0(Processor *pCpu, const char *pName, const char *pDesc) :
	CM12CON0(pCpu, pName, pDesc) {}
  ~CM2CON0() {}

  virtual void state_change(unsigned int cmcon_val);
  virtual double CVref();
};
class CM1CON0_2 : public CM12CON0
{
 public:
  CM1CON0_2(Processor *pCpu, const char *pName, const char *pDesc) :
	CM12CON0(pCpu, pName, pDesc) {}
  ~CM1CON0_2();

  virtual void state_change(unsigned int cmcon_val);
  virtual double CVref();
};
class CM2CON0_2 : public CM12CON0
{
 public:
  CM2CON0_2(Processor *pCpu, const char *pName, const char *pDesc) :
	CM12CON0(pCpu, pName, pDesc) {}
  ~CM2CON0_2() {}

  virtual void state_change(unsigned int cmcon_val);
  virtual double CVref();
};
// The following classes are for comparators which have 3 registers
//
class CMxCON1;
class ComparatorModule2;

class CMxCON0 : public sfr_register
{
 public:

  enum 
    {
      CxSYNC 	= 1<<0,	// Output Synchronous Mode bit
      CxHYS 	= 1<<1,	// Hysteresis Enable bit
      CxSP   	= 1<<2,	// Speed/Power Select bit
      CxZLF	= 1<<3, // Zero Latency Filter Enable bit
      CxPOL 	= 1<<4,	// Output polarity select bit
      CxOE  	= 1<<5,	// Output enable
      CxOUT 	= 1<<6,	// Output bit 
      CxON  	= 1<<7,	// Enable bit
    };

  CMxCON0(Processor *pCpu, const char *pName, const char *pDesc, unsigned int x, ComparatorModule2 *);
  ~CMxCON0();
  void put(unsigned int);
  unsigned int  get();
  void setBitMask(unsigned int bm) { mValidBits = bm; }

protected:

  unsigned int cm;	// comparator number
  CMxCON1	*m_cmxcon1;
  ComparatorModule2 *m_cmModule;
  PeripheralSignalSource *cm_source;
};
// CMxCON1 only uses 1 0r 2 of Negative select bits and 2 Positive select bits
class CMxCON1 : public sfr_register
{
 public:

  enum 
    {
      CxNCH0 	= 1<<0,	//  Negative Input Channel Select bits
      CxNCH1 	= 1<<1,	//  Negative Input Channel Select bits
      CxNCH2 	= 1<<2,	//  Negative Input Channel Select bits
      CxPCH0	= 1<<3, //  Positive Input Channel Select bits
      CxPCH1	= 1<<4, //  Positive Input Channel Select bits
      CxPCH2	= 1<<5, //  Positive Input Channel Select bits
      CxINTN 	= 1<<6,	//  Interrupt on Negative Going Edge Enable bits
      CxINTP  	= 1<<7,	//  Interrupt on Positive Going Edge Enable bits
      CxNMASK = (CxNCH0 | CxNCH1 | CxNCH2),
      CxPMASK = (CxPCH0 | CxPCH1 | CxPCH2),
      NEG	= 0,
      POS	= 1,

    };
  CMxCON1(Processor *pCpu, const char *pName, const char *pDesc, unsigned int _x, ComparatorModule2 *);
  ~CMxCON1();

  void setBitMask(unsigned int bm) { mValidBits = bm; }
  void put(unsigned int new_value);
  double get_Vpos();
  double get_Vneg();
  void setPinStimulus(PinModule *, bool);
  void set_INpinNeg(PinModule *pin_cm0, PinModule *pin_cm1, PinModule *pin_cm2=0,  PinModule *pin_cm3=0,  PinModule *pin_cm4=0);
  void set_OUTpin(PinModule *pin_cm0);
  void set_INpinPos(PinModule *pin_cm0, PinModule *pin_cm1=0);
  PinModule *output_pin() { return cm_output; }

protected:

  unsigned int cm;	// comparator number
  CM_stimulus 		*cm_stimulus[2];
  PinModule		*stimulus_pin[2];
  PinModule 		*cm_inputNeg[5];
  PinModule 		*cm_inputPos[2];
  PinModule 		*cm_output;
  ComparatorModule2 	*m_cmModule;
};
class CMOUT : public sfr_register
{
 public:

    void put(unsigned int val) { return;} // Read only by user

    CMOUT(Processor *pCpu, const char *pName, const char *pDesc)
  : sfr_register(pCpu, pName, pDesc) {}

};

// uses CMxCON0, CMxCON1, CMOUT
class ComparatorModule2
{
 public:

  ComparatorModule2(Processor *);
  ~ComparatorModule2();

  void run_get(unsigned int comp) { cmxcon0[comp]->get();}


  void set_DAC_volt(double);
  void set_FVR_volt(double);
  void set_cmout(unsigned int bit, bool value);
  void set_if(unsigned int);
  void assign_pir_set(PIR_SET *new_pir_set){ pir_set = new_pir_set;}
  void assign_t1gcon(T1GCON *_t1gcon) { t1gcon = _t1gcon;}
  void assign_sr_module(SR_MODULE *_sr_module) { sr_module = _sr_module;}

  CMxCON0	*cmxcon0[4];
  CMxCON1 	*cmxcon1[4];
  CMOUT		*cmout;

//protected:
  double 	DAC_voltage;
  double 	FVR_voltage;
  PIR_SET 	*pir_set;
  T1GCON	*t1gcon;
  SR_MODULE	*sr_module;

};
#endif // __COMPARATOR_H__
