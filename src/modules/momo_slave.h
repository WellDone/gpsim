#ifndef __MOMO_SLAVE_H__
#define __MOMO_SLAVE_H__

/* IN_MODULE should be defined for modules */
#define IN_MODULE

#include "momo.h"

namespace MomoModule
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

class MomoSlave : public MomoDevice 
{
	public:
	MomoSlave(const char *name);
	virtual ~MomoSlave();

	static Module * construct(const char *name);

	private:
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
	virtual MomoResponse handle_mib_endpoint(uint8_t sender, uint16_t command, const std::vector<uint8_t> &params);

	virtual void new_sda_edge(bool value);
	virtual void new_scl_edge(bool value);

	void log_error(const std::string &message);
	void log_packet(std::ofstream &log, const std::vector<uint8_t> &data);
	void prepare_response(MomoResponse &resp);
};

};

#endif
