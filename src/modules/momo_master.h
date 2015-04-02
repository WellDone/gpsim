#ifndef __MOMO_MASTER_H__
#define __MOMO_MASTER_H__

#define IN_MODULE
#include "momo.h"

namespace MoMoModule 
{

enum MasterState
{
	kMasterIdle,
	kMasterSendingData,
	kMasterReceivingData
};

class MoMoMaster : public I2C_Module::I2CMaster
{
	protected:
	std::vector<uint8_t>	send_data;
	size_t					send_i;

	std::vector<uint8_t>	receive_data;
	size_t					receive_i;

	MasterState 			state;

	public:
	MoMoMaster(const char *name);
	virtual ~MoMoMaster();

	static Module * construct(const char *name);

	virtual void startCompleted();
    virtual void stopCompleted();
    virtual void transferCompleted();
};

};

#endif