#include "momo_slave.h"
#include <string>
#include <fstream>
#include <iomanip>

namespace MomoModule
{

MomoSlave::MomoSlave(const char *new_name) : MomoDevice(new_name), address_value("address", 0, "I2C Address"),
											 log_value("logfile", "mib_calls.log", "Path to log file")
{
	addSymbol(&address_value);
	addSymbol(&log_value);

	state = kIdleState;
	send_acknowledge = kNoAcknowledge;
	ack_value = false;
}

MomoSlave::~MomoSlave()
{

}

Module * MomoSlave::construct(const char *name)
{
	return new MomoSlave(name);
}

bool MomoSlave::is_start_condition(bool sda_edge)
{
	if (sda_edge == false && scl->getDrivenState() == true)
		return true;

	return false;
}

bool MomoSlave::is_stop_condition(bool sda_edge)
{
	if (sda_edge == true && scl->getDrivenState() == true)
		return true;

	return false;
}

void MomoSlave::begin_reading()
{
	current_byte = 0;
	bits_read = 0;
}

void MomoSlave::begin_writing()
{
	current_i = 0;
	bits_written = 0;
}

/*
 * Shift in 1 bit and if we have shifted in an entire byte, return true
 */
bool MomoSlave::shift_read_bit()
{
	bool value = sda->getDrivenState();

	current_byte <<= 1;
	current_byte |= int(value);

	++bits_read;

	if (bits_read == 8)
		return true;

	return false;
}

void MomoSlave::acknowledge_byte(bool ack)
{
	send_acknowledge = kStartAcknowledge;
	ack_value = ack;
}

void MomoSlave::log_error(const std::string &message)
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

void MomoSlave::log_packet(std::ofstream &log, const std::vector<uint8_t> &data)
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

MomoResponse MomoSlave::handle_mib_endpoint(uint8_t sender, uint16_t command, const std::vector<uint8_t> &params)
{
	//Return a command not found response since this endpoint (like all endpoints...) has not been implemented
	MomoResponse resp;
	resp.status = kCommandNotFoundCode;

	return resp;
}

void MomoSlave::prepare_response(MomoResponse &resp)
{
	uint8_t sum;
	std::ofstream log;
	std::string logfile = log_value.getVal();

	//Log that we received this valid mib packet
	if (logfile.size() > 0)
		log.open(logfile.c_str(), std::ios_base::app);

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

/*
 * Validate that the data we received was appropriate and
 * if we have a log file specified, log that we received
 * the packet.  Subclasses can choose to respond in their
 * own ways.
 */
void MomoSlave::process_mib_packet()
{
	uint8_t sum = 0;
	if (data.size() != kMIBPacketLength)
	{
		log_error("Invalid packet length");
		return;
	}

	for (size_t i=0; i<data.size(); ++i)
		sum += data[i];

	//Validate checksum or return an error
	if (sum != 0)
	{
		log_error("Invalid packet checksum");

		MomoResponse resp;
		resp.status = kCommandNotFoundCode;
		prepare_response(resp);
		return;
	}

	//Log reception of packet
	std::string logfile = log_value.getVal();

	//Log that we received this valid mib packet
	if (logfile.size() > 0)
	{
		//Open log inside this block so that it autocloses.
		std::ofstream log;
		log.open(logfile.c_str(), std::ios_base::app);

		log << "VALID MIB PACKET: ";
		log_packet(log, data);
		log << "\n";
	}

	uint8_t length, sender;
	uint16_t command_id;

	command_id = (((uint16_t)data[3]) << 8) | data[2];
	length = data[0] & 0b11111; //5 low order bits are length, 3 high bits are reserved
	sender = data[1];

	//Copy over the parameters and call the handler function
	std::vector<uint8_t> params;
	for (int i=4; i < (kMIBPacketLength-1); ++i)
		params.push_back(data[i]);

	params.resize(length);

	MomoResponse resp;
	resp = handle_mib_endpoint(sender, command_id, params);
	prepare_response(resp);
}

void MomoSlave::new_scl_edge(bool value)
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

void MomoSlave::new_sda_edge(bool value)
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
