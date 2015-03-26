#include "momo_slave.h"
#include <string>
#include <fstream>
#include <iomanip>

namespace MoMoSlaveModule
{

class I2CPin : public IO_open_collector
{
	public:
	MoMoSlave *slave;

	I2CPin (MoMoSlave *new_slave, const char *_name): IO_open_collector(_name), slave(new_slave)
	{
		bDrivingState = true;
		bDrivenState = true;

		// Make the pin an output.
		update_direction(IO_bi_directional::DIR_OUTPUT,true);
	}

	void setDrivingState(bool new_state) 
	{
		bDrivingState = new_state;
		bDrivenState = new_state;

		if(snode)
			snode->update();
	}
};


class I2CSDAPin : public I2CPin
{
	public:
	I2CSDAPin(MoMoSlave *new_slave, const char *_name) : I2CPin (new_slave, _name)
	{

	}

	void setDrivenState(bool new_dstate) 
	{
		bool diff = new_dstate ^ bDrivenState;

		if(slave && diff) 
		{
			bDrivenState = new_dstate;
			slave->new_sda_edge(new_dstate);
		}
	}
};

class I2CSCLPin : public I2CPin
{
	public:
	I2CSCLPin(MoMoSlave *new_slave, const char *_name) : I2CPin (new_slave, _name)
	{

	}

	void setDrivenState(bool new_dstate) 
	{
		bool diff = new_dstate ^ bDrivenState;

		if(slave && diff) 
		{
			bDrivenState = new_dstate;
			slave->new_scl_edge(new_dstate);
		}
	}
};

MoMoSlave::MoMoSlave(const char *new_name) : Module(new_name, "momoslave"), package(2), address_value("address", 0, "I2C Address"),
											 log_value("logfile", "mib_calls.log", "Path to log file")
{
	std::string pin_name;

	pin_name = name() + ".sda";
	sda = new I2CSDAPin(this, pin_name.c_str());

	pin_name = name() + ".scl";
	scl = new I2CSCLPin(this, pin_name.c_str());

	package.assign_pin(1, scl);
	package.assign_pin(2, sda);

	addSymbol(&address_value);
	addSymbol(&log_value);

	state = kIdleState;
	send_acknowledge = kNoAcknowledge;
	ack_value = false;
}

MoMoSlave::~MoMoSlave()
{
	delete sda;
	delete scl;
}

Module * MoMoSlave::construct(const char *name)
{
	return new MoMoSlave(name);
}

bool MoMoSlave::is_start_condition(bool sda_edge)
{
	if (sda_edge == false && scl->getDrivenState() == true)
		return true;

	return false;
}

bool MoMoSlave::is_stop_condition(bool sda_edge)
{
	if (sda_edge == true && scl->getDrivenState() == true)
		return true;

	return false;
}

void MoMoSlave::begin_reading()
{
	current_byte = 0;
	bits_read = 0;
}

void MoMoSlave::begin_writing()
{
	current_i = 0;
	bits_written = 0;
}

/*
 * Shift in 1 bit and if we have shifted in an entire byte, return true
 */
bool MoMoSlave::shift_read_bit()
{
	bool value = sda->getDrivenState();

	current_byte <<= 1;
	current_byte |= int(value);

	++bits_read;

	if (bits_read == 8)
		return true;

	return false;
}

void MoMoSlave::acknowledge_byte(bool ack)
{
	send_acknowledge = kStartAcknowledge;
	ack_value = ack;
}

void MoMoSlave::log_error(const std::string &message)
{
	std::ofstream log;
	std::string logfile = log_value.getVal();

	if (logfile.size() == 0)
		return;

	log.open(logfile.c_str(), std::ios_base::app);

	log << "INVALID MIB PACKET:" << message << ": ";
	log_packet(log, data);
	log << "\n";
}

void MoMoSlave::log_packet(std::ofstream &log, const std::vector<uint8_t> &data)
{
	log << "[";
	for (size_t i=0; i< data.size(); ++i)
	{
		if (i>0)
			log << ", ";

		log << "0x" << std::hex << int(data[i]);
	}

	log << "]";
}

MomoResponse MoMoSlave::handle_mib_endpoint(uint8_t feature, uint8_t command, uint8_t type, uint8_t sender, const std::vector<uint8_t> &params)
{
	//Return a busy response
	MomoResponse resp;
	resp.status = 0;

	return resp;
}

/*
 * Validate that the data we received was appropriate and
 * if we have a log file specified, log that we received
 * the packet.  Subclasses can choose to respond in their
 * own ways.
 */
void MoMoSlave::process_mib_packet()
{
	uint8_t	sum = 0;

	if (data.size() != kMIBPacketLength)
	{
		log_error("Invalid packet length");
		return;
	}

	for (size_t i=0; i<data.size(); ++i)
		sum += data[i];

	//Validate checksum
	if (sum != 0)
	{
		log_error("Invalid packet checksum");
		return; 
	}

	//Log reception of packet
	std::ofstream log;
	std::string logfile = log_value.getVal();

	//Log that we received this valid mib packet
	if (logfile.size() > 0)
	{
		log.open(logfile.c_str(), std::ios_base::app);

		log << "VALID MIB PACKET: ";
		log_packet(log, data);
		log << "\n";
	}

	uint8_t feature, command, type, sender;
	feature = data[0];
	command = data[1];
	type = data[2];
	sender = data[3];

	//Copy over the parameters and call the handler function
	std::vector<uint8_t> params;
	for (int i=4; i < (kMIBPacketLength-1); ++i)
		params.push_back(data[i]);

	MomoResponse resp;
	resp = handle_mib_endpoint(feature, command, type, sender, params);

	//Copy the response back
	resp.response.resize(kMIBDataLength);
	data.resize(kMIBPacketLength);

	data[0] = resp.status;
	data[1] = (~resp.status) + 1;
	data[2] = 0;
	data[3] = (uint8_t)resp.response.size();

	sum = data[3];
	for (size_t i=0; i<resp.response.size(); ++i)
	{
		sum += resp.response[i];
		data[i+4] = resp.response[i];
	}

	data[kMIBPacketLength - 1] = (~sum) + 1;

	//Log that we received this valid mib packet
	if (logfile.size() > 0)
	{
		log << "RESPONSE: 0x" << std::hex << int(resp.status) << ": ";
		log_packet(log, data);
		log << "\n"; 
	}
}

void MoMoSlave::new_scl_edge(bool value)
{
	if (value && (state == kReadingAddress || state == kReadingData) && send_acknowledge == kNoAcknowledge)
	{
		bool done_reading = shift_read_bit();
		
		if (done_reading)
		{
			if (state == kReadingAddress)
			{
				/*
				 * Only acknowledge and respond to queries send to our address.  
				 * If we are being written to, just start to clock in the bytes 
				 * that will form the MIB packet and header.  
				 * 
				 * If we are being read from, first execute the command
				 * contained in the current MIB buffer and then get ready to send
				 * the response.
				 */

				uint8_t send_addr = current_byte >> 1;
				bool	reading   = (current_byte & 1);

				if (send_addr != address_value.getVal())
				{
					acknowledge_byte(false);
					state = kIdleState;
				}
				else if (reading == false)
				{
					data.clear();
					acknowledge_byte(true);
					begin_reading();
					state = kReadingData;
					first_read = true;
				}
				else
				{
					acknowledge_byte(true);

					//Only call the handler the first time we are asked for data since subsequent calls
					//are only to try to get the data that we've already read
					if (first_read)
					{
						process_mib_packet();
						first_read = false;
					}

					state = kWritingData;
					begin_writing();
				}
			}
			else if (state == kReadingData)
			{
				acknowledge_byte(true);
				data.push_back(current_byte);
				begin_reading();
			}
		}
	}

	//Send appropriate acknowledge bit if required
	if (value == false && send_acknowledge == kStartAcknowledge)
	{
		sda->setDrivingState(!ack_value);
		send_acknowledge = kFinishAcknowledge;
	}
	else if (value == false && send_acknowledge == kFinishAcknowledge)
	{
		sda->setDrivingState(true);
		send_acknowledge = kNoAcknowledge;
	}

	/* If we're responding, clock out data on falling clock edges
	 * We only clock out a data bit on the falling edge of a clock pulse under the following conditions
	 * - we are asked to write data (i.e. the master is reading frmo us)
	 * - the bit is bit 0-7 of the 9-bit words (the last bit is for the master to acknowledge)
	 * - we are writing the first byte after the address or the master ACKed our last byte.
	 *	 if the master NACKED our last byte then we must not write another bit so as to not lock the bus.
	 */
	if (value == false && state == kWritingData && send_acknowledge == kNoAcknowledge)
	{
		//Make sure that if we're starting a new byte, the last one wasn't NACKed
		if (!(current_i > 0 && bits_written == 0 && sda->getDrivenState() == true))
		{
			uint8_t byteval = 0;
			if (current_i < data.size())
				byteval = data[current_i];

			//Data is clocked out MSB first
			bool bit = (byteval & (1 << (7-bits_written)));
			sda->setDrivingState(bit);

			++bits_written;
			if (bits_written == 8)
			{
				acknowledge_byte(false); //Give the bus to the master to acknowledge the byte;
				bits_written = 0;
				++current_i;
			}
		}
	}

}

void MoMoSlave::new_sda_edge(bool value)
{
	if (is_start_condition(value))
	{
		state = kReadingAddress;
		begin_reading();
	}
	else if (is_stop_condition(value))
		state = kIdleState;
}

};