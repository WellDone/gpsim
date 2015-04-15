//momo_master.cc

#include "momo_master_behave.h"

namespace MomoModule 
{

MomoMasterBehavior::MomoMasterBehavior(I2CSCLPin *new_scl, I2CSDAPin *new_sda) : scl(new_scl), sda(new_sda)
{
	state = kMasterIdle;
	bp_manager = &get_cycles();
	next_bp = 0;
	microstate = kIdleMicrostate;
	picostate = kNotWaiting;
}

MomoMasterBehavior::~MomoMasterBehavior()
{

}

void MomoMasterBehavior::resend()
{
	state = kMasterSendingData;
	send_i = 0;
	receive_i = 0;

	check_and_start();
}

void MomoMasterBehavior::send(uint8_t new_addr, const std::vector<uint8_t> &data)
{
	address = new_addr;

	send_data.resize(data.size() + 1);
	for (size_t i=0; i<data.size(); ++i)
		send_data[i+1] = data[i];

	send_data[0] = address << 1;
	resend();	
}

void MomoMasterBehavior::check_and_start()
{
	microstate = kCheckingBus;

	num_bus_checks = 0;
	set_bp(1);
}

void MomoMasterBehavior::check_bus()
{
	if (sda->getDrivenState() == false || scl->getDrivenState() == false)
		check_and_start();

	++num_bus_checks;

	if (num_bus_checks == kNumCheckCycles)
		microstate = kBeginningStart;

	set_bp(1);
}

void MomoMasterBehavior::begin_start()
{
	sda->setDrivingState(false);
	microstate = kFinishingStart;
	set_bp(kNumHalfBaudCycles);
}

void MomoMasterBehavior::finish_start()
{
	scl->setDrivingState(false);
	microstate = kStartSendingData;
	set_bp(1);
}

void MomoMasterBehavior::begin_send_bit()
{
	current_bit = current_byte & (1 << (7 - bit_i));

	sda->setDrivingState(current_bit);

	picostate = kWaitingLow;
	microstate = kSendingBit;

	set_bp(kNumHalfBaudCycles);
}

void MomoMasterBehavior::begin_receive_bit()
{
	sda->setDrivingState(true);

	picostate = kWaitingLow;
	microstate = kReceivingBit;

	set_bp(kNumHalfBaudCycles);
}

void MomoMasterBehavior::begin_receive_ack()
{
	sda->setDrivingState(true);

	picostate = kWaitingLow;
	microstate = kReceivingAck;

	set_bp(kNumHalfBaudCycles);
}

void MomoMasterBehavior::begin_send_ack(bool ack)
{
	sda->setDrivingState(!ack);

	picostate = kWaitingLow;
	microstate = kSendingAck;

	set_bp(kNumHalfBaudCycles);
}

void MomoMasterBehavior::begin_repeated_start()
{
	sda->setDrivingState(true);
	
	microstate = kAboutToSendRepeatedStart;
	set_bp(kNumHalfBaudCycles);
}

void MomoMasterBehavior::begin_stop()
{
	sda->setDrivingState(false);
	microstate = kBeginningStop;
	set_bp(kNumHalfBaudCycles);
}

void MomoMasterBehavior::continue_stop()
{
	scl->setDrivingState(true);
	microstate = kFinishingStop;
	set_bp(kNumHalfBaudCycles);
}

void MomoMasterBehavior::finish_stop()
{
	sda->setDrivingState(true);
	microstate = kIdleMicrostate;
}

void MomoMasterBehavior::begin_receive_data_byte()
{
	bit_i  = 0;
	current_byte = 0;

	begin_receive_bit();
}

void MomoMasterBehavior::begin_send_data_byte()
{
	/*
	 * Precondition is that scl is low and sda is unknown
	 */

	if (scl->getDrivenState() != false)
	 	printf("Clock is not low at the beginning of a byte transaction, this is a bus logic error.\n");

	current_byte = send_data[send_i];
	bit_i = 0;

	begin_send_bit();
}

void MomoMasterBehavior::callback()
{
	switch (state)
	{
		case kMasterSendingData:
		case kMasterSendingReadAddress:
		send_callback();
		break;

		case kMasterReceivingData:
		case kMasterFinishingRead:
		receive_callback();
		break;

		case kMasterIdle:
		printf("Idle state in MomoMasterBehavior::callback().  Should not happen.\n");
	}
}

void MomoMasterBehavior::process_response()
{
	printf("Calling command function.\n");
}

void MomoMasterBehavior::receive_callback()
{
	switch(microstate)
	{
		case kBeginningStop:
		continue_stop();
		break;

		case kFinishingStop:
		finish_stop();
		if (read_status == kStopReading)
			process_response();
		else if (read_status == kResendCommand)
			resend();
		break;

		case kReceivingBit:
		case kSendingAck:
		if (picostate == kWaitingLow)
		{
			picostate = kWaitingForHigh;
			scl->masterDrive(true); //make sure we get notified when the transition happens.
		}
		else if (picostate == kWaitingHigh)
		{
			scl->setDrivingState(false);
			picostate = kNotWaiting;

			if (bit_i < 7)
			{
				//Save off the last bit
				current_byte |= (current_bit & 0b1) << (7-bit_i);

				++bit_i;
				begin_receive_bit();
			}
			else if (bit_i == 7 && microstate == kReceivingBit)
			{
				//Save off the LSB
				current_byte |= (current_bit & 0b1) << (7-bit_i);
				begin_send_ack(!nack_next_byte);
				nack_next_byte = false;
			}
			else if (microstate == kSendingAck && state == kMasterFinishingRead)
				begin_stop();
			else if (microstate == kSendingAck && state == kMasterRestartingRead)
			{
				state = kMasterSendingReadAddress;
				begin_repeated_start();
			}
			else if (microstate == kSendingAck)
			{
				//This is where we go in the logic if we have just finished receiving and acknowledging
				//or NACKing a byte.
				receive_data.push_back(current_byte);

				++receive_i;
				if (receive_i < 2)
					begin_receive_data_byte();
				else if (receive_i == 2)
					check_return_status();
			}
		}
	}
}

void MomoMasterBehavior::check_return_status()
{
	uint8_t status, check;

	status = receive_data[0];
	check = receive_data[1];

	if (status == 0xFF && check == 0xFF)
	{
		nack_next_byte = true;
		state = kMasterFinishingRead;
		read_status = kStopReading;

		begin_receive_data_byte();
	}
	else if ( (status + check)  & 0xFF)
	{
		nack_next_byte = true;
		state = kMasterRestartingRead;
		read_status = kRestartRead;

		begin_receive_data_byte();
	}
	else if (status == kChecksumMismatchCode)
	{
		read_status = kResendCommand;
		nack_next_byte = true;
		state = kMasterFinishingRead;

		begin_receive_data_byte();
	}
	else
	{
		bool has_data = status & (1 << 7);
		if (!has_data)
		{
			nack_next_byte = true;
			state = kMasterFinishingRead;
			read_status = kStopReading;

			begin_receive_data_byte();
		}
	}
}

void MomoMasterBehavior::send_callback()
{
	switch (microstate)
	{
		case kCheckingBus:
		check_bus();
		break;

		case kBeginningStart:
		begin_start();
		break;

		case kFinishingStart:
		finish_start();
		break;

		case kIdleMicrostate:
		printf("Callback when we are in idle microstate in MomoMasterBehavior.\n");
		break;

		case kAboutToSendRepeatedStart:
		scl->setDrivingState(true);
		set_bp(kNumHalfBaudCycles);
		microstate = kBeginningRepeatedStart;
		break;

		case kBeginningRepeatedStart:
		sda->setDrivingState(false);
		set_bp(kNumHalfBaudCycles);
		microstate = kFinishingRepeatedStart;
		break;

		case kFinishingRepeatedStart:
		scl->setDrivingState(false);
		current_byte = address << 1 | 1;
		bit_i = 0;
		begin_send_bit();
		break;

		case kStartSendingData:
		state = kMasterSendingData;
		begin_send_data_byte();
		break;

		case kSendingBit:
		case kReceivingAck:
		if (picostate == kWaitingLow)
		{
			picostate = kWaitingForHigh;
			scl->masterDrive(true); //make sure we get notified when the transition happens.
		}
		else if (picostate == kCheckingSDA)
		{
			if (current_bit != sda->getDrivenState())
				resend();

			++num_sda_checks;
			if (num_sda_checks == (kNumHalfBaudCycles-1))
				picostate = kWaitingHigh;

			set_bp(1);
		}
		else if (picostate == kWaitingHigh)
		{
			scl->setDrivingState(false);
			picostate = kNotWaiting;

			if (bit_i < 7)
			{
				++bit_i;
				begin_send_bit();
			}
			else if (bit_i == 7 && microstate == kSendingBit)
				begin_receive_ack();
			else if (microstate == kReceivingAck && state == kMasterSendingReadAddress)
			{
				//We just finished sending the address.
				state = kMasterReceivingData;

				//Start receiving data bytes
				receive_i = 0;
				receive_data.clear();

				begin_receive_data_byte();
			}
			else if (microstate == kReceivingAck)
			{
				++send_i;
				if (send_i < send_data.size())
					begin_send_data_byte();
				else
				{
					state = kMasterSendingReadAddress;
					begin_repeated_start();
				}
			}
		}
		break;

		default:
		printf("Unhandled microstate occurred.\n");
		break;
	}
}

void MomoMasterBehavior::set_bp(guint64 in_cycles)
{
	guint64 now = bp_manager->get();
	guint64 next = now + in_cycles;

	if (next_bp)
		bp_manager->reassign_break(next_bp, next, this);
	else
		bp_manager->set_break(next, this);

	next_bp = next;
}

void MomoMasterBehavior::new_sda_edge(bool value)
{

}

void MomoMasterBehavior::new_scl_edge(bool value)
{
	if (value && picostate == kWaitingForHigh)
	{
		//FIXME: Change this so that we continually check to make sure our bit is what is being output
		if (microstate == kReceivingBit || kReceivingAck)
		{
			set_bp(kNumHalfBaudCycles);
			picostate = kWaitingHigh;
			current_bit = sda->getDrivenState();
		}
		else
		{
			picostate = kCheckingSDA;
			num_sda_checks = 0;
			set_bp(1);
		}
	}
	else if (!value && picostate == kWaitingHigh)
		callback(); //If someone pulled scl low while we were waiting high, cut our wait short
}

}
