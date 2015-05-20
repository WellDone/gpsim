## Process this file with automake to produce Makefile.in

AM_CPPFLAGS = @X_CFLAGS@

lib_LTLIBRARIES = libgpsim_modules.la

libgpsim_modules_la_SOURCES = \
	gpsim_modules.cc \
	module_attribute.h \
	resistor.cc resistor.h \
	usart.cc usart.h \
	switch.cc switch.h \
	logic.cc logic.h \
	led.cc led.h \
	push_button.cc push_button.h \
	encoder.cc encoder.h \
	i2c-eeprom.cc i2c-eeprom.h \
	momo_slave_behave.cc momo_slave_behave.h \
	momo_python_slave_behave.cc momo_python_slave_behave.h \
	momo.cc momo.h \
	momo_python_slave.cc momo_python_slave.h \
	momo_master_behave.cc momo_master_behave.h \
	momo_triggered_master.cc momo_triggered_master.h \
	stimuli.h stimuli.cc \
	ttl.cc ttl.h \
	video.cc video.h \
	i2c.cc i2c.h
 # TSD - removed 17APR06 #PGS added back
##	paraface.cc paraface.h \  # TSD - removed 16APR06

libgpsim_modules_la_LIBADD = ../eXdbm/libgpsim_eXdbm.la -lstdc++ -lpopt \
  @X_LDFLAGS@ @Y_LDFLAGS@ @LIBREADLINE@ ../src/libgpsim.la

EXTRA_DIST = makefile.mingw
