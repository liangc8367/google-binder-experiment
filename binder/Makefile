# makefile to build a test service and clients
# liangc, 2015/11/24

INC_PATH=../include
CPPFLAGS=-g -std=c++11 -I$(INC_PATH) 
#-std=gnu++11

OBJS=\
	binderThroughputTest.o \
	ProcessState.o \
	Parcel.o \
	IServiceManager.o \
	Binder.o \
	BpBinder.o \
	Static.o \
	IPCThreadState.o
	
UTIL_OBJS=\
	String16.o \
	String8.o \
	Threads.o \
	RefBase.o \
	VectorImpl.o
	
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

Binder.o : Binder.cpp
	g++ $(CPPFLAGS) -c -o $@ $<
	
BpBinder.o : BpBinder.cpp
	g++ $(CPPFLAGS) -c -o $@ $<

Static.o : Static.cpp
	g++ $(CPPFLAGS) -c -o $@ $<

IPCThreadState.o : IPCThreadState.cpp
	g++ $(CPPFLAGS) -c -o $@ $<
	
### library ###
LIBUTILS_PATH=../libutils
String16.o : $(LIBUTILS_PATH)/String16.cpp
	g++ $(CPPFLAGS) -c -o $@ $<

String8.o : $(LIBUTILS_PATH)/String8.cpp
	g++ $(CPPFLAGS) -c -o $@ $<
	
Threads.o : $(LIBUTILS_PATH)/Threads.cpp
	g++ $(CPPFLAGS) -c -o $@ $<

RefBase.o : $(LIBUTILS_PATH)/RefBase.cpp
	g++ $(CPPFLAGS) -c -o $@ $<

VectorImpl.o : $(LIBUTILS_PATH)/VectorImpl.cpp
	g++ $(CPPFLAGS) -c -o $@ $<