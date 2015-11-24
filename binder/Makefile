# makefile to build a test service and clients
# liangc, 2015/11/24

INC_PATH=../include
CPPFLAGS=-g -std=c++11 -I$(INC_PATH) 
#-std=gnu++11

OBJS=\
	binderThroughputTest.o \
	String16.o
	
binder_throughput_test : $(OBJS)
	g++ -o $@ $<

binderThroughputTest.o : tests/binderThroughputTest.cpp
	g++ $(CPPFLAGS) -c -o $@ $<

### library ###
LIBUTILS_PATH=../libutils
String16.o : $(LIBUTILS_PATH)/String16.cpp
	g++ $(CPPFLAGS) -c -o $@ $<