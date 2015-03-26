#include "momo_python_slave.h"
#include <string>

namespace MoMoSlaveModule 
{

size_t MoMoPythonSlave::num_instances = 0;

MoMoPythonSlave::MoMoPythonSlave(const char *name) : MoMoSlave(name), python_module("python_module", "", "path to python module implementing this MIB slave"),
													 initialized(false), module_object(NULL), handler_object(NULL)
{
	addSymbol(&python_module);
	Py_Initialize();
	PySys_SetPath("."); //make sure we can find modules in our current working dir

	++num_instances;
}

MoMoPythonSlave::~MoMoPythonSlave()
{
	--num_instances;

	if (module_object)
		Py_DECREF(module_object);

	if (handler_object)
		Py_DECREF(handler_object);

	if (num_instances == 0)
		Py_Finalize();
}

void MoMoPythonSlave::load_module()
{
	std::string module_string = python_module.getVal();

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

Module* MoMoPythonSlave::construct(const char *name)
{
	return new MoMoPythonSlave(name);
}

/*
 * Check if retval is a valid sequence object and attempt to unpack it into a vector
 * for sending on the line.  
 * 
 * retval should be a sequence of 2 items, with the first an integer (status code)
 * and the second a sequence that contains the response if there is one.
 */
bool MoMoPythonSlave::interpret_response(PyObject *retval, uint8_t *status, std::vector<uint8_t> &output)
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

	return true;
}

MomoResponse MoMoPythonSlave::handle_mib_endpoint(uint8_t feature, uint8_t command, uint8_t type, uint8_t sender, const std::vector<uint8_t> &params)
{
	MomoResponse resp;
	bool 		 success = false;
	
	load_module();
	
	if (initialized == true)
	{
		PyObject *args = PyTuple_New(5);
		if (args != NULL)
		{
			PyObject *feature_obj 	= PyInt_FromLong(feature);
			PyObject *cmd_obj 		= PyInt_FromLong(command);
			PyObject *type_obj 		= PyInt_FromLong(type);
			PyObject *sender_obj 	= PyInt_FromLong(sender);
			PyObject *params_obj	= PyTuple_New(params.size());

			if (feature_obj && cmd_obj && type_obj && sender_obj && params_obj)
			{
				bool can_call = true;

				PyTuple_SetItem(args, 0, feature_obj);
				feature_obj = NULL;

				PyTuple_SetItem(args, 1, cmd_obj);
				cmd_obj = NULL;

				PyTuple_SetItem(args, 2, type_obj);
				type_obj = NULL;

				PyTuple_SetItem(args, 3, sender_obj);
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

				PyTuple_SetItem(args, 4, params_obj);
				params_obj = NULL;

				if (can_call)
				{
					PyObject *retval = PyObject_CallObject(handler_object, args);
					if (retval)
					{
						if (interpret_response(retval, &resp.status, resp.response))
							success = true;
						else
							printf("Could not interpret response from python code.\n");

						Py_DECREF(retval);
					}
				}

				Py_DECREF(args); //tuple holds the refs to all of its contents so they are released as well
			}

			if (feature_obj)
				Py_DECREF(feature_obj);

			if (cmd_obj)
				Py_DECREF(cmd_obj);

			if (type_obj)
				Py_DECREF(type_obj);

			if (sender_obj)
				Py_DECREF(sender_obj);

			if (params_obj)
				Py_DECREF(params_obj);			
		}
	}

	if (success == false)
	{
		printf("MoMoPythonSlave called but python code could not be loaded or executed successfully.\n");
		resp.status = 0b00000000;
		resp.response.clear();
	}
	
	return resp;
}

};