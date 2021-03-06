# makefile to build a test service and clients
# liangc, 2015/11/24

INC_PATH=../include
COMM_FLAGS=-D__ANDROID__ 
## not supported in stock binder driver -DHAS_BC_ATTEMPT_ACQUIRE=1
CPPFLAGS=-g -std=c++11 -I$(INC_PATH) $(COMM_FLAGS)
CFLAGS=-g -std=c11 -I$(INC_PATH) $(COMM_FLAGS)

OBJS=\
	ProcessState.o \
	IPCThreadState.o \
	Parcel.o \
	Binder.o \
	BpBinder.o \
	Static.o \
	TextOutput.o \
	Debug.o \
	IInterface.o \
	BufferedTextOutput.o \
	IServiceManager.o \
	IPermissionController.o
		
UTIL_OBJS=\
	Unicode.o \
	String16.o \
	String8.o \
	Threads.o \
	RefBase.o \
	VectorImpl.o \
	SharedBuffer.o \
	SystemClock.o \
	UtilStatic.o \
	Timers.o
	
CUTIL_OBJS=\
	threads.o	\
	sched_policy.o
	
binder_throughput_test : binder_throughput_test.o $(OBJS) $(UTIL_OBJS) $(CUTIL_OBJS)
	g++ -pthread -o $@ binder_throughput_test.o $(OBJS) $(UTIL_OBJS) $(CUTIL_OBJS)
	
demo_service : demo_service.o IDemoInterface.o $(OBJS) $(UTIL_OBJS) $(CUTIL_OBJS)
	g++ -pthread -o $@ demo_service.o IDemoInterface.o $(OBJS) $(UTIL_OBJS) $(CUTIL_OBJS)
	
demo_client : demo_client.o IDemoInterface.o $(OBJS) $(UTIL_OBJS) $(CUTIL_OBJS)
	g++ -pthread -o $@ demo_client.o IDemoInterface.o $(OBJS) $(UTIL_OBJS) $(CUTIL_OBJS)

IDemoInterface.o : tests/IDemoInterface.cpp
	g++ $(CPPFLAGS) -c -o $@ $<
		
clean:
	rm -f binder_throughput_test demo_service.* demo_client.* IDemoService.o $(OBJS) $(UTIL_OBJS) $(CUTIL_OBJS)

binderThroughputTest.o : tests/binderThroughputTest.cpp
	g++ $(CPPFLAGS) -c -o $@ $<
	
demo_service.o : tests/demoService.cpp
	g++ $(CPPFLAGS) -c -o $@ $<	

demo_client.o : tests/demoClient.cpp
	g++ $(CPPFLAGS) -c -o $@ $<	

ProcessState.o : ProcessState.cpp
	g++ $(CPPFLAGS) -c -o $@ $<

Parcel.o : Parcel.cpp
	g++ $(CPPFLAGS) -c -o $@ $<

IInterface.o : IInterface.cpp
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
	
TextOutput.o : TextOutput.cpp
	g++ $(CPPFLAGS) -c -o $@ $<

Debug.o : Debug.cpp
	g++ $(CPPFLAGS) -c -o $@ $<

BufferedTextOutput.o : BufferedTextOutput.cpp
	g++ $(CPPFLAGS) -c -o $@ $<

IPermissionController.o : IPermissionController.cpp
	g++ $(CPPFLAGS) -c -o $@ $<

### C++ library ###
LIBUTILS_PATH=../libutils

Unicode.o : $(LIBUTILS_PATH)/Unicode.cpp
	g++ $(CPPFLAGS) -c -o $@ $<

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

SharedBuffer.o : $(LIBUTILS_PATH)/SharedBuffer.cpp
	g++ $(CPPFLAGS) -c -o $@ $<	
	
SystemClock.o : $(LIBUTILS_PATH)/SystemClock.cpp
	g++ $(CPPFLAGS) -c -o $@ $<		
	
Timers.o : $(LIBUTILS_PATH)/Timers.cpp
	g++ $(CPPFLAGS) -c -o $@ $<		

UtilStatic.o : $(LIBUTILS_PATH)/Static.cpp
	g++ $(CPPFLAGS) -c -o $@ $<		

	
#### C libraries #####
LIBCUTILS_PATH=../libcutils
threads.o : $(LIBCUTILS_PATH)/threads.c
	gcc $(CFLAGS) -c -o $@ $<

sched_policy.o : $(LIBCUTILS_PATH)/sched_policy.c
	gcc $(CFLAGS) -c -o $@ $<
	