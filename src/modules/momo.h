#ifndef __MOMO_H__
#define __MOMO_H__

#define IN_MODULE

#include "../src/modules.h"
#include "../src/ioports.h"
#include "../src/stimuli.h"
#include "../src/packages.h"
#include "../src/value.h"
#include "i2c.h"
#include <stdint.h>
#include <vector>
#include <fstream>
#include <Python.h>

namespace MomoModule 
{

#define kMIBHeaderLength	4
#define kMIBDataLength		20
#define kMIBPacketLength	(kMIBHeaderLength + kMIBDataLength + 1)

#define kModuleBusyCode				0x00
#define kChecksumMismatchCode 		0x01
#define kCommandNotFoundCode		0x02

struct MomoCommand
{
	uint8_t length;
	uint8_t sender;

	uint16_t command;

	std::vector<uint8_t> params;
};

struct MomoResponse
{
	uint8_t				 status;
	std::vector<uint8_t> response;
};

class MomoDevice;

class I2CPin : public IO_open_collector
{
	public:
	MomoDevice *slave;

	I2CPin (MomoDevice *new_slave, const char *_name): IO_open_collector(_name), slave(new_slave)
	{
		bDrivingState = true;
		bDrivenState = true;

		// Make the pin an output.
		update_direction(IO_bi_directional::DIR_OUTPUT, true);
	}

	void setDrivingState(bool new_state) 
	{
		bDrivingState = new_state;
		bDrivenState = new_state;

		if(snode)
			snode->update();
	}

	void masterDrive(bool new_state)
	{
		bDrivingState = new_state;

		if (snode)
			snode->update();
	}
};


class I2CSDAPin : public I2CPin
{
	public:
	I2CSDAPin(MomoDevice *new_slave, const char *_name) : I2CPin (new_slave, _name)
	{

	}

	void setDrivenState(bool new_dstate);
};

class I2CSCLPin : public I2CPin
{
	public:
	I2CSCLPin(MomoDevice *new_slave, const char *_name) : I2CPin (new_slave, _name)
	{

	}

	void setDrivenState(bool new_dstate);
};

/*
 * Generic interface for momo simulator devices that interact with the i2c
 * momo bus.
 */
class MomoDevice : public Module 
{
	public:
	MomoDevice(const char *name);
	virtual ~MomoDevice();

	virtual void new_sda_edge(bool value) = 0;
	virtual void new_scl_edge(bool value) = 0;

	private:
	Package 	package;

	protected:
	I2CSCLPin	*scl;
	I2CSDAPin	*sda;
};

//Helper Functions
PyObject *	load_python_module(const std::string &path);
PyObject *	load_python_function(PyObject *module, const std::string &function_name);

};

class MomoDataSource
{
	public:
	virtual ~MomoDataSource() {};
	virtual uint8_t generate_call(std::vector<uint8_t> &out_params) = 0;
};

#endif
