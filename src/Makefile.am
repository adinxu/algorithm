
noinst_LIBRARIES = libinterface.a
libinterface_a_SOURCES = interface.c interface.h 
#when each type libraries ref each other,only .so depend .a make sence.
#libinterface_a_LIBADD = ../parallelmenu/libparallelmenu.la

bin_PROGRAMS = algorithm
algorithm_SOURCES = main.c interface.h
#when libraries depend make no sence,just link it all in programs
algorithm_LDADD = libinterface.a ../parallelmenu/libparallelmenu.la ../sort/libbst.la
