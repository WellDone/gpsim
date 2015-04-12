#include "momo_triggered_master.h"

namespace MomoModule
{

extern size_t num_python_instances;

MomoTriggeredMaster::MomoTriggeredMaster(const char *new_name) : MomoDevice(new_name), master(scl, sda),
																 trigger("trigger_cycle", 1, "cycle to trigger the transmission"),
																 state(kCheckTriggerState), module_object(NULL),
																 handler_object(NULL), initialized(false),
																 python_module("python_module", "", "python module")
{
	bp_manager = &get_cycles();
	addSymbol(&trigger);
	addSymbol(&python_module);

	bp_manager->set_break(1, this);

	Py_Initialize(); //Can be called any number of times with no ill effects
	PySys_SetPath("."); //make sure we can find modules in our current working dir

	++num_python_instances;
}

MomoTriggeredMaster::~MomoTriggeredMaster()
{
	--num_python_instances;

	if (module_object)
		Py_DECREF(module_object);

	if (handler_object)
		Py_DECREF(handler_object);

	if (num_python_instances == 0)
		Py_Finalize();
}

void MomoTriggeredMaster::initialize_python()
{
	if (initialized)
		return;

	module_object = load_python_module(std::string(python_module.getVal()));
	if (module_object == NULL)
		return;

	handler_object = load_python_function(module_object, std::string(kMasterFunctionName));
	if (handler_object == NULL)
		return;

	initialized = true;
}

bool MomoTriggeredMaster::load_call_data()
{
	PyObject *args = PyTuple_New(0);
	if (!args)
		return false;

	PyObject *retval = PyObject_CallObject(handler_object, args);
	PyObject *err = PyErr_Occurred();

	Py_DECREF(args);
	if (err)
	{
		Py_XDECREF(retval);
		printf("Exception occurred in triggered master python function, not processing any further.\n");
		return false;
	}

	if (PySequence_Check(retval) == 0)
	{
		Py_DECREF(retval);
		printf("Invalid response from python code, was not a sequence object\n");
		return false;
	}

	if (PySequence_Length(retval) != 3)
	{
		Py_DECREF(retval);
		printf("Invalid response from python code, was not a sequence of length 3\n");
		return false;
	}

	PyObject *my_addr_obj 	= PySequence_GetItem(retval, 0);
	PyObject *send_addr_obj = PySequence_GetItem(retval, 1);
	PyObject *params_obj 	= PySequence_GetItem(retval, 2);

	Py_DECREF(retval);

	//Check to make sure we got 2 numbers and a sequence
	if (!my_addr_obj || !send_addr_obj || !params_obj || !PyNumber_Check(my_addr_obj) || 
		!PyNumber_Check(send_addr_obj) || !PySequence_Check(params_obj))
	{
		printf("Invalid response from python code, should return 2 numbers and a sequence");
		Py_XDECREF(my_addr_obj);
		Py_XDECREF(send_addr_obj);
		Py_XDECREF(params_obj);
		return false;
	}

	uint8_t my_address, to_address;
	my_address = (uint8_t)PyNumber_AsSsize_t(my_addr_obj, NULL);
	to_address = (uint8_t)PyNumber_AsSsize_t(send_addr_obj, NULL);
	Py_DECREF(my_addr_obj);
	Py_DECREF(send_addr_obj);

	size_t len = PySequence_Length(params_obj);
	std::vector<uint8_t>	params;

	params.resize(len);
	for (size_t i=0; i<len;++i)
	{
		PyObject *obj = PySequence_GetItem(params_obj, i);
		if (!obj || !PyNumber_Check(obj))
		{
			printf("Could not get item %lu in params sequence and convert it to a number.\n", i);
			Py_DECREF(params_obj);
			return false;
		}

		uint8_t val = PyNumber_AsSsize_t(obj, NULL);
		params[i] = val;

		Py_DECREF(obj);
	}

	master.send(to_address, params);
	return true;
}

void MomoTriggeredMaster::callback()
{
	if (state == kCheckTriggerState)
	{
		unsigned long cycle = trigger.getVal();

		bp_manager->reassign_break(1, cycle, this);
		state = kTriggerState;
	}
	else if (state == kTriggerState)
	{
		initialize_python();
		if (!initialized)
		{
			printf("Could not properly initialize python, triggered master will do nothing.\n");
			return;
		}

		load_call_data();
	}
}

void MomoTriggeredMaster::new_sda_edge(bool value)
{
	master.new_sda_edge(value);
}

void MomoTriggeredMaster::new_scl_edge(bool value)
{
	master.new_scl_edge(value);
}

Module *MomoTriggeredMaster::construct(const char *name)
{
	return new MomoTriggeredMaster(name);
}

}