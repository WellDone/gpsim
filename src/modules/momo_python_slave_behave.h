#ifndef __MOMO_PYTHON_SLAVE_BEHAVE_H__
#define __MOMO_PYTHON_SLAVE_BEHAVE_H__

#include "momo_slave_behave.h"
#include <Python.h>

#define kMoMoSlavePythonFunction "handle_mib_endpoint"

#define kMoMoBusyException		 "BusyException"
#define kMoMoNotFoundException	 "EndpointNotFoundException"
#define kMoMoChecksumException	 "ChecksumMismatchException"

namespace MomoModule 
{

class MomoPythonSlaveBehavior : public MomoSlaveBehavior
{
	public:
	MomoPythonSlaveBehavior(I2CSCLPin *new_scl, I2CSDAPin *new_sda);
	virtual ~MomoPythonSlaveBehavior();

	void set_module(const std::string &module);

	protected:
	virtual MomoResponse handle_mib_endpoint(uint8_t sender, uint16_t command, const std::vector<uint8_t> &params);

	private:
	bool		initialized;

	PyObject 	*module_object;
	PyObject	*handler_object;

	std::string	module_string;

	void load_module();
	bool interpret_response(PyObject *retval, uint8_t *status, std::vector<uint8_t> &output);
	bool interpret_exception(uint8_t *status, std::vector<uint8_t> &output);
};

}

#endif