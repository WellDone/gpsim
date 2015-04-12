#include "momo.h"

namespace MomoModule 
{

void I2CSDAPin::setDrivenState(bool new_dstate) 
{
	bool diff = new_dstate ^ bDrivenState;

	IO_open_collector::setDrivenState(new_dstate);

	if(slave && diff) 
		slave->new_sda_edge(new_dstate);
}

void I2CSCLPin::setDrivenState(bool new_dstate) 
{
	bool diff = new_dstate ^ bDrivenState;

	IO_open_collector::setDrivenState(new_dstate);

	if(slave && diff) 
		slave->new_scl_edge(new_dstate);
}

MomoDevice::MomoDevice(const char *new_name) : Module(new_name, "Momo Simulated Device"), package(2)
{
	std::string pin_name;

	pin_name = name() + ".sda";
	sda = new I2CSDAPin(this, pin_name.c_str());

	pin_name = name() + ".scl";
	scl = new I2CSCLPin(this, pin_name.c_str());

	package.assign_pin(1, scl);
	package.assign_pin(2, sda);
}

MomoDevice::~MomoDevice()
{
	delete sda;
	delete scl;
}

PyObject *load_python_module(const std::string &path)
{
	if (path.size() == 0)
		return NULL;

	PyObject *module_path = PyString_FromString(path.c_str());
	if (module_path == NULL)
		return NULL;

	PyObject *module_obj = PyImport_Import(module_path);

	Py_DECREF(module_path);
	return module_obj;
}

PyObject *load_python_function(PyObject *module, const std::string &function_name)
{
	PyObject *handler = PyObject_GetAttrString(module, function_name.c_str());
	if (handler == NULL || !PyCallable_Check(handler))
		return NULL;

	return handler;
}

};