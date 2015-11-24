# makefile to build a test service and clients
# liangc, 2015/11/24

INC_PATH=../include
CPPFLAGS=-I$(INC_PATH) -g -std=c++11 
#-std=gnu++11

binder_throughput_test : binderThroughputTest.o

binderThroughputTest.o : tests/binderThroughputTest.cpp
	g++ $(CPPFLAGS) -o $@ -c $<