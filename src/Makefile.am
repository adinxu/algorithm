
noinst_LIBRARIES = libinterface.a
libinterface_a_SOURCES = interface.c interface.h 
#libinterface_a_LIBADD = ../parallelmenu/libparallelmenu.la

bin_PROGRAMS = algorithm
algorithm_SOURCES = main.c interface.h
algorithm_LDADD = libinterface.a ../parallelmenu/libparallelmenu.la
