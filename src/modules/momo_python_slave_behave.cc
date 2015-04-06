#include "momo_python_slave_behave.h"
#include <string>

namespace MomoModule 
{

//Global keeping track of how many python modules are running so that we don't finalize too soon when
//we destruct a python using class like this one.
size_t num_python_instances = 0;

MomoPythonSlaveBehavior::MomoPythonSlaveBehavior(I2CSCLPin *new_scl, I2CSDAPin *new_sda) :
						 MomoSlaveBehavior(new_scl, new_sda), initialized(false), module_object(NULL), 
						 handler_object(NULL)
{
	Py_Initialize(); //Can be called any number of times with no ill effects
	PySys_SetPath("."); //make sure we can find modules in our current working dir

	++num_python_instances;
}

MomoPythonSlaveBehavior::~MomoPythonSlaveBehavior()
{
	--num_python_instances;

	if (module_object)
		Py_DECREF(module_object);

	if (handler_object)
		Py_DECREF(handler_object);

	if (num_python_instances == 0)
		Py_Finalize();
}

void MomoPythonSlaveBehavior::set_module(const std::string &module)
{
	if (initialized == true)
	{
		printf("Cannot reload a different python module after the module has been initialized.\n");
		return;
	}

	module_string = module;
}

void MomoPythonSlaveBehavior::load_module()
{
	if (initialized == true)
		return;

	if (module_string.size() == 0)
		return;

	PyObject *module_path = PyString_FromString(module_string.c_str());
	if (module_path == NULL)
		return;

	PyObject *module_obj = PyImport_Import(module_path);

	Py_DECREF(module_path);
	if (module_obj == NULL)
		return;

	PyObject *handler = PyObject_GetAttrString(module_obj, kMoMoSlavePythonFunction);
	if (handler == NULL || !PyCallable_Check(handler))
	{
		Py_DECREF(module_obj);
		return;
	}

	module_object = module_obj;
	handler_object = handler;
	initialized = true;
}

/*
 * To be called when a python exception is set, set the response status based on  
 * which exception was thrown.
 */
bool MomoPythonSlaveBehavior::interpret_exception(uint8_t *status, std::vector<uint8_t> &output)
{
	bool success = false;
	PyObject *err = PyErr_Occurred();

	if (err == NULL)
	{
		printf("No exception occured in python code, yet interpret_exception was called.\n");
		return false;
	}

	Py_INCREF(err);

	//Get all of the appropriate exception types that we understand
	PyObject *busy_exc = NULL, *notfound_exc = NULL, *checksum_exc = NULL;

	if (!module_object)
	{
		printf("Could not get main module from python code.\n");
		goto done;
	}

	//These are all new references.
	if (PyObject_HasAttrString(module_object, kMoMoBusyException))
		busy_exc = PyObject_GetAttrString(module_object, kMoMoBusyException);

	if (PyObject_HasAttrString(module_object, kMoMoNotFoundException))
		notfound_exc = PyObject_GetAttrString(module_object, kMoMoNotFoundException);

	if (PyObject_HasAttrString(module_object, kMoMoChecksumException))
		checksum_exc = PyObject_GetAttrString(module_object, kMoMoChecksumException);

	if (!busy_exc)
		printf("Could not load \"module busy\" exception from module.\n");

	if (!notfound_exc)
		printf("Could not load \"not found\" exception from module.\n");

	if (!checksum_exc)
		printf("Could not load \"checksum mismatch\" exception from module.\n");

	success = true;
	output.clear();

	if (busy_exc && PyErr_GivenExceptionMatches(err, busy_exc))
		*status = kModuleBusyCode;
	else if (notfound_exc && PyErr_GivenExceptionMatches(err, notfound_exc))
		*status = kCommandNotFoundCode;
	else if (checksum_exc && PyErr_GivenExceptionMatches(err, checksum_exc))
		*status = kChecksumMismatchCode;
	else
	{
		printf("Unknown exception caught from python code in interpret_exception.\n");

		success = false;
	}

	done:
	if (busy_exc)
		Py_DECREF(busy_exc);
	if (notfound_exc)
		Py_DECREF(notfound_exc);
	if (checksum_exc)
		Py_DECREF(checksum_exc);
	if (err)
		Py_DECREF(err);

	PyErr_Clear();

	return success;
}

/*
 * Check if retval is a valid sequence object and attempt to unpack it into a vector
 * for sending on the line.  
 * 
 * retval should be a sequence of 2 items, with the first an integer (status code)
 * and the second a sequence that contains the response if there is one.
 */
bool MomoPythonSlaveBehavior::interpret_response(PyObject *retval, uint8_t *status, std::vector<uint8_t> &output)
{
	if (PySequence_Check(retval) == 0)
	{
		printf("Invalid response from python code, was not a sequence object\n");
		return false;
	}

	if (PySequence_Length(retval) != 2)
	{
		printf("Invalid response from python code, was not a sequence of length 2\n");
		return false;
	}

	PyObject *status_obj = PySequence_GetItem(retval, 0);
	PyObject *value_obj = PySequence_GetItem(retval, 1);

	if (!status_obj || !value_obj)
	{
		printf("Invalid response from python code, could not get 2 items from return value\n");
		Py_XDECREF(status_obj);
		Py_XDECREF(value_obj);
		return false;
	}

	if (PyNumber_Check(status_obj) == 0)
	{
		printf("Invalid response from python code, first item in tuple not a number.\n");
		Py_XDECREF(status_obj);
		Py_XDECREF(value_obj);
		return false;
	}

	*status = (uint8_t)PyNumber_AsSsize_t(status_obj, NULL);
	Py_DECREF(status_obj);

	//Set the app defined bit since we got this status from the application.
	*status |= 1 << 6;

	if (PySequence_Check(value_obj) == 0)
	{
		printf("Invalid response from python code, second item is not a sequence.\n");
		Py_DECREF(value_obj);
		return false;
	}

	size_t len = PySequence_Length(value_obj);

	output.resize(len);
	for (size_t i=0; i<len; ++i)
	{
		PyObject *obj = PySequence_GetItem(value_obj, i);
		if (!obj)
			continue;

		uint8_t val = PyNumber_AsSsize_t(obj, NULL);
		output[i] = val;

		Py_DECREF(obj);
	}

	//If we have data, set the has_data bit of the response.
	if (len > 0)
		*status |= 1 << 7;

	return true;
}

MomoResponse MomoPythonSlaveBehavior::handle_mib_endpoint(uint8_t sender, uint16_t command, const std::vector<uint8_t> &params)
{
	MomoResponse resp;
	bool 		 success = false;
	
	load_module();
	
	if (initialized == true)
	{
		PyObject *args = PyTuple_New(3);
		if (args != NULL)
		{
			PyObject *cmd_obj 		= PyInt_FromLong(command);
			PyObject *sender_obj 	= PyInt_FromLong(sender);
			PyObject *params_obj	= PyTuple_New(params.size());

			if (cmd_obj && sender_obj && params_obj)
			{
				bool can_call = true;

				PyTuple_SetItem(args, 0, cmd_obj);
				cmd_obj = NULL;

				PyTuple_SetItem(args, 1, sender_obj);
				sender_obj = NULL;

				//Create the param tuple with bytes
				for (size_t i=0; i<params.size(); ++i)
				{
					PyObject *obj = PyInt_FromLong(params[i]);
					if (obj == NULL)
					{
						can_call = false;
						break;
					}

					PyTuple_SetItem(params_obj, i, obj);
				}

				PyTuple_SetItem(args, 2, params_obj);
				params_obj = NULL;

				if (can_call)
				{
					PyObject *retval = PyObject_CallObject(handler_object, args);

					//If an exception was set, figure out what kind it was so that we can set the appropriate
					//response status.
					PyObject *err = PyErr_Occurred();
					if (err)
					{
						printf("Exception was thrown during execution.\n");
						success = interpret_exception(&resp.status, resp.response);
					}
					else if (retval)
					{
						if (interpret_response(retval, &resp.status, resp.response))
							success = true;
						else
							printf("Could not interpret response from python code.\n");
					}

					if (retval)
						Py_DECREF(retval);
				}

				Py_DECREF(args); //tuple holds the refs to all of its contents so they are released as well
			}

			if (cmd_obj)
				Py_DECREF(cmd_obj);

			if (sender_obj)
				Py_DECREF(sender_obj);

			if (params_obj)
				Py_DECREF(params_obj);			
		}
	}

	if (success == false)
	{
		printf("MoMoPythonSlave called but python code could not be loaded or executed successfully.\n");
		resp.status = kModuleBusyCode;
		resp.response.clear();
	}
	
	return resp;
}

};