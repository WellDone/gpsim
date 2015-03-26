#ifndef __MOMO_SLAVE_H__
#define __MOMO_SLAVE_H__

#define kMIBHeaderLength	4
#define kMIBDataLength		20
#define kMIBPacketLength	(kMIBHeaderLength + kMIBDataLength + 1)

/* IN_MODULE should be defined for modules */
#define IN_MODULE

#include "../src/modules.h"
#include "../src/ioports.h"
#include "../src/stimuli.h"
#include "../src/packages.h"
#include "../src/value.h"
#include <stdint.h>
#include <vector>
#include <fstream>

namespace MoMoSlaveModule
{

//Forward Declarations
class I2CSDAPin;
class I2CSCLPin;

enum MoMoSlaveState
{
	kIdleState,
	kReadingAddress,
	kReadingData,
	kWritingData
};

enum AcknowledgeState
{
	kStartAcknowledge,
	kFinishAcknowledge,
	kNoAcknowledge
};

struct MomoResponse
{
	uint8_t				 status;
	std::vector<uint8_t> response;
};

class MoMoSlave : public Module 
{
	public:
	MoMoSlave(const char *name);
	virtual ~MoMoSlave();

	static Module * construct(const char *name);

	void new_sda_edge(bool value);
	void new_scl_edge(bool value);

	private:
	Package 			package;
	I2CSCLPin			*scl;
	I2CSDAPin			*sda;

	Integer				address_value;
	String				log_value;

	uint8_t				current_byte;
	uint8_t				bits_read;

	uint8_t				bits_written;
	size_t				current_i;

	AcknowledgeState	send_acknowledge;
	bool				ack_value;
	MoMoSlaveState		state;

	bool				first_read;

	std::vector<uint8_t> data;

	bool is_stop_condition(bool sda_edge);
	bool is_start_condition(bool sda_edge);
	void acknowledge_byte(bool ack);

	void begin_reading();
	void begin_writing();
	bool shift_read_bit();

	protected:
	virtual void process_mib_packet();
	virtual MomoResponse handle_mib_endpoint(uint8_t feature, uint8_t command, uint8_t type, uint8_t sender, const std::vector<uint8_t> &params);

	void log_error(const std::string &message);
	void log_packet(std::ofstream &log, const std::vector<uint8_t> &data);
};

};

#endif