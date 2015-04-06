#include "momo.h"

namespace MomoModule 
{

void I2CSDAPin::setDrivenState(bool new_dstate) 
{
	bool diff = new_dstate ^ bDrivenState;

	if(slave && diff) 
	{
		bDrivenState = new_dstate;
		slave->new_sda_edge(new_dstate);
	}
}

void I2CSCLPin::setDrivenState(bool new_dstate) 
{
	bool diff = new_dstate ^ bDrivenState;

	if(slave && diff) 
	{
		bDrivenState = new_dstate;
		slave->new_scl_edge(new_dstate);
	}
}

MomoDevice::MomoDevice(const char *new_name) : Module(new_name, "Momo Simulated Device"), package(2)
{
	std::string pin_name;

	pin_name = name() + ".sda";
	sda = new I2CSDAPin(this, pin_name.c_str());

	pin_name = name() + ".scl";
	scl = new I2CSCLPin(this, pin_name.c_str());

	package.assign_pin(1, scl);
	package.assign_pin(2, sda);
}

MomoDevice::~MomoDevice()
{
	delete sda;
	delete scl;
}

};