#ifndef __MOMO_TRIGGERED_MASTER_H__
#define __MOMO_TRIGGERED_MASTER_H__

#include "momo_master_behave.h"
#include "momo.h"

#define kMasterFunctionName		"prepare_call"
#define kMasterProcessorName 	"process_response"

namespace MomoModule
{

enum TriggeredMasterState
{
	kCheckTriggerState = 0,
	kTriggerState
};

class MomoTriggeredMaster : public TriggerObject, MomoDevice
{
	private:
	Cycle_Counter			*bp_manager;

	MomoMasterBehavior		master;
	Integer					trigger;
	String					python_module;

	TriggeredMasterState	state;

	PyObject 				*module_object;
	PyObject				*handler_object;
	bool					initialized;

	void 					initialize_python();
	bool					load_call_data();

	public:
	MomoTriggeredMaster(const char *name);
	virtual ~MomoTriggeredMaster();

	virtual void callback();
	virtual void new_sda_edge(bool value);
	virtual void new_scl_edge(bool value);

	static Module *construct(const char *name);
};

}

#endif
