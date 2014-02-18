CC=g++
CFLAGS=-c
SRC=/home/adey/MICE/Tracker/mice-tracker-cm
INCLUDE=-I $(SRC)/HardwareInterfaces/ -I $(SRC)/Base/ -I ${SRC}/DataStructure/

all: HardwareInterfaces 	

HardwareInterfaces: TrInterfaceProgrammer.o TrFPGAProgrammer.o TrPICProgrammer.o \
	Tr1553Programmer.o TrVMEProgrammer.o TrTriPtProgrammer.o TrBiasProgrammer.o \
	TrPICWrapper.o Tr1553Wrapper.o TrVMEWrapper.o TrProgrammer.o
	ar -rcv libHardwareInterfaces.a TrInterfaceProgrammer.o TrFPGAProgrammer.o TrPICProgrammer.o \
	Tr1553Programmer.o TrVMEProgrammer.o TrTriPtProgrammer.o TrBiasProgrammer.o \
	TrPICWrapper.o Tr1553Wrapper.o TrVMEWrapper.o TrProgrammer.o
	ranlib libHardwareInterfaces.a

TrInterfaceProgrammer.o: TrInterfaceProgrammer.cc
	$(CC) $(CFLAGS) $(INCLUDE) TrInterfaceProgrammer.cc

TrFPGAProgrammer.o: TrFPGAProgrammer.cc
	$(CC) $(CFLAGS) $(INCLUDE) TrFPGAProgrammer.cc

TrPICProgrammer.o: TrPICProgrammer.cc
	$(CC) $(CFLAGS) $(INCLUDE) TrPICProgrammer.cc

TrPICWrapper.o: TrPICWrapper.cc
	$(CC) $(CFLAGS) $(INCLUDE) TrPICWrapper.cc

Tr1553Programmer.o: Tr1553Programmer.cc
	$(CC) $(CFLAGS) $(INCLUDE) Tr1553Programmer.cc

Tr1553Wrapper.o: Tr1553Wrapper.cc
	$(CC) $(CFLAGS) $(INCLUDE) Tr1553Wrapper.cc

TrVMEProgrammer.o: TrVMEProgrammer.cc
	$(CC) $(CFLAGS) $(INCLUDE) TrVMEProgrammer.cc

TrVMEWrapper.o: TrVMEWrapper.cc
	$(CC) $(CFLAGS) $(INCLUDE) TrVMEWrapper.cc

TrProgrammer.o: TrProgrammer.cc
	$(CC) $(CFLAGS) $(INCLUDE) TrProgrammer.cc

TrBiasProgrammer.o: TrBiasProgrammer.cc
	$(CC) $(CFLAGS) $(INCLUDE) TrBiasProgrammer.cc

TrTriPtProgrammer.o: TrTriPtProgrammer.cc
	$(CC) $(CFLAGS) $(INCLUDE) TrTriPtProgrammer.cc

clean: 
	rm -rf *o HardwareInterfaces.a
