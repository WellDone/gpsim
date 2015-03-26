#ifndef __MOMO_PYTHON_SLAVE_H__
#define __MOMO_PYTHON_SLAVE_H__

#include "momo_slave.h"
#include <Python.h>

#define kMoMoSlavePythonFunction "handle_mib_endpoint"

namespace MoMoSlaveModule 
{

class MoMoPythonSlave : public MoMoSlave
{
	public:
	MoMoPythonSlave(const char *name);
	virtual ~MoMoPythonSlave();

	static Module* construct(const char *name);

	protected:
	virtual MomoResponse handle_mib_endpoint(uint8_t feature, uint8_t command, uint8_t type, uint8_t sender, const std::vector<uint8_t> &params);
	static size_t num_instances;

	private:
	String		python_module;
	bool		initialized;

	PyObject 	*module_object;
	PyObject	*handler_object;

	void load_module();
	bool interpret_response(PyObject *retval, uint8_t *status, std::vector<uint8_t> &output);
};

};

#endif