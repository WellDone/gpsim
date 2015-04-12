#ifndef __MOMO_MASTER_BEHAVE_H__
#define __MOMO_MASTER_BEHAVE_H__

#define IN_MODULE
#include "momo.h"
#include "../src/gpsim_time.h"
#include "../src/trigger.h"

#define kNumHalfBaudCycles		5
#define kNumBaudCycles 			10
#define kNumCheckCycles 		(kNumBaudCycles*2)

namespace MomoModule 
{

enum MasterState
{
	kMasterIdle,
	kMasterSendingData,
	kMasterReceivingData,
	kMasterSendingReadAddress,
	kMasterFinishingRead,
	kMasterRestartingRead
};

enum MasterMicroState
{
	kIdleMicrostate,
	kActiveIdleMicrostate, //Idle but with the clock held low
	kCheckingBus,
	kBeginningStart,
	kFinishingStart,
	kStartSendingData,
	kSendingBit,
	kReceivingAck,
	kBeginningRepeatedStart,
	kFinishingRepeatedStart,
	kReceivingBit,
	kSendingAck,
	kBeginningStop,
	kFinishingStop
};

enum MasterPicoState
{
	kNotWaiting,
	kWaitingLow,
	kWaitingForHigh,
	kWaitingHigh,
	kCheckingSDA
};

enum MasterReturnStatus
{
	kStopReading,
	kResendCommand,
	kRestartRead,
	kContinueReading
};

class MomoMasterBehavior : public TriggerObject
{
	protected:
	I2CSCLPin				*scl;
	I2CSDAPin				*sda;

	std::vector<uint8_t>	send_data;
	size_t					send_i;

	std::vector<uint8_t>	receive_data;
	size_t					receive_i;

	MasterState 			state;
	MasterMicroState		microstate;
	MasterPicoState			picostate;

	Cycle_Counter			*bp_manager;
	guint64					next_bp;

	//Bus Idle Checking
	size_t					num_bus_checks;
	size_t					num_sda_checks;

	//Data byte sending/receiving
	uint8_t					current_byte;
	bool					current_bit;
	size_t					bit_i;

	uint8_t					address;
	bool					nack_next_byte;

	MasterReturnStatus		read_status;


	void set_bp(guint64 in_cycles);

	void process_response();

	private:
	void begin_start();
	void finish_start();
	void check_bus();
	void check_and_start();
	void begin_send_bit();
	void begin_receive_ack();
	void begin_send_data_byte();
	void begin_repeated_start();
	void begin_receive_bit();
	void begin_send_ack(bool ack);
	void begin_receive_data_byte();
	void begin_stop();

	void send_callback();
	void receive_callback();

	void resend();

	void check_return_status();

	public:
	MomoMasterBehavior(I2CSCLPin *new_scl, I2CSDAPin *new_sda);
	virtual ~MomoMasterBehavior();

	virtual void callback();

	void new_sda_edge(bool value);
	void new_scl_edge(bool value);

	void send(uint8_t address, const std::vector<uint8_t> &data);
};

}

#endif
