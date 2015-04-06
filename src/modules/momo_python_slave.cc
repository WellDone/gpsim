#include "momo_python_slave.h"

namespace MomoModule
{

MomoPythonSlave::MomoPythonSlave(const char *new_name) : MomoDevice(new_name), python_slave(scl, sda),
											address_sym("address", 127, "I2C Address"),
											log_file_sym("logfile", "mib_calls.log", "Path to log file"),
											module_path_sym("python_module", "", "Path to python module file")
{
	addSymbol(&address_sym);
	addSymbol(&log_file_sym);
	addSymbol(&module_path_sym);
}

MomoPythonSlave::~MomoPythonSlave()
{

}

void MomoPythonSlave::check_update_variables()
{
	if (address != address_sym.getVal())
	{
		address = address_sym.getVal();
		python_slave.set_address(address);
	}

	if (log_file != log_file_sym.getVal())
	{
		log_file = log_file_sym.getVal();
		python_slave.set_logpath(log_file);
	}

	if (module_path != module_path_sym.getVal())
	{
		module_path = module_path_sym.getVal();
		python_slave.set_module(module_path);
	}
}

void MomoPythonSlave::new_sda_edge(bool value)
{
	check_update_variables();
	python_slave.new_sda_edge(value);
}

void MomoPythonSlave::new_scl_edge(bool value)
{
	check_update_variables();
	python_slave.new_scl_edge(value);
}

Module * MomoPythonSlave::construct(const char *name)
{
	return new MomoPythonSlave(name);
}

}
