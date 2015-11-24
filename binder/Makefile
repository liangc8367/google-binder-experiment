# makefile to build a test service and clients
# liangc, 2015/11/24

INC_PATH=../include
CPPFLAGS=-g -std=c++11 -I$(INC_PATH) 
#-std=gnu++11

OBJS=\
	binderThroughputTest.o \
	ProcessState.o \
	Parcel.o \
	IServiceManager.o
	
UTIL_OBJS=\
	String16.o \
	RefBase.o
	
binder_throughput_test : $(OBJS) $(UTIL_OBJS)
	g++ -o $@ $(OBJS) $(UTIL_OBJS)

binderThroughputTest.o : tests/binderThroughputTest.cpp
	g++ $(CPPFLAGS) -c -o $@ $<

ProcessState.o : ProcessState.cpp
	g++ $(CPPFLAGS) -c -o $@ $<

Parcel.o : Parcel.cpp
	g++ $(CPPFLAGS) -c -o $@ $<

IServiceManager.o : IServiceManager.cpp
	g++ $(CPPFLAGS) -c -o $@ $<

### library ###
LIBUTILS_PATH=../libutils
String16.o : $(LIBUTILS_PATH)/String16.cpp
	g++ $(CPPFLAGS) -c -o $@ $<
	
RefBase.o : $(LIBUTILS_PATH)/RefBase.cpp
	g++ $(CPPFLAGS) -c -o $@ $<
