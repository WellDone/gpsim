//momo_master.cc

#include "momo_master.h"

namespace MoMoModule 
{

MoMoMaster::MoMoMaster(const char *new_name) : Module(new_name, "momomaster"), send_i(0), receive_i(0), state(kMasterIdle)
{

}

MoMoMaster::~MoMoMaster()
{

}

Module * MoMoMaster::construct(const char *name)
{
	return new MoMoMaster(name);
}

void MoMoMaster::startCompleted()
{
	if (state == kMasterSendingData)
	{
		send_i = 0;

		if (send_i >= send_data.size())
		{
			printf("Logic error: master is still trying to send data but the send_data buffer is too short.\n");
			return;
		}

		this->send8BitData(send_data[send_i++]);
	}
}

void MoMoMaster::stopCompleted()
{

}

void MoMoMaster::transferCompleted()
{
	if (state == kMasterSendingData)
	{
		if (send_i == send_data.size())
		{
			state = kMasterReceivingData;
			this->sendStart();
		}
	}
	else if (state == kMasterReceivingData)
	{
		
	}
}

};
