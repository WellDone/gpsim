#ifndef __MOMO_PYTHON_SLAVE_H__
#define __MOMO_PYTHON_SLAVE_H__

#include "momo_python_slave_behave.h"

#include "momo.h"

namespace MomoModule
{

class MomoPythonSlave : MomoDevice
{
	private:
	MomoPythonSlaveBehavior python_slave;

	Integer					address_sym;
	String					log_file_sym;
	String					module_path_sym;

	unsigned int 			address;
	std::string 			log_file;
	std::string 			module_path;

	void check_update_variables();

	public:
	MomoPythonSlave(const char *name);
	virtual ~MomoPythonSlave();

	static Module *construct(const char *name);

	virtual void new_sda_edge(bool value);
	virtual void new_scl_edge(bool value);
};

}

#endif
