# makefile for linux module

#### WARNING ####
# please sudo gen_deps.sh to generate deps.h
####

obj-m := binderplus.o

binderplus-y := binder.o deps.o

KDIR ?= /lib/modules/`uname -r`/build

all:
	make -C $(KDIR) M=$(PWD) modules
