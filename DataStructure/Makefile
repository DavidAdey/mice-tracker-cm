CC=g++
CFLAGS=-c
SRC=/home/adey/MICE/Tracker/mice-tracker-cm
INCLUDE=-I $(SRC)/DataStructure/ -I $(SRC)/Base/

all: DataStructure 	

DataStructure: TrAFEInitialisationState.o TrAFEBoardInitialisationState.o \
	TrCommandList.o TrFPGACommandList.o TrTriPtInitialisationState.o \
	TrBiasInitialisationState.o TrTemperatureInitialisationState.o \
	TrAnalogueInitialisationState.o TrDigitalInitialisationState.o \
	TrAFEObject.o TrDecodePair.o TrVMECommandList.o Tr1553CommandList.o
	ar -rcv libDataStructure.a TrAFEInitialisationState.o TrAFEBoardInitialisationState.o \
	TrFPGACommandList.o TrTriPtInitialisationState.o TrBiasInitialisationState.o \
	TrTemperatureInitialisationState.o TrAnalogueInitialisationState.o \
	TrDigitalInitialisationState.o TrAFEObject.o TrDecodePair.o TrCommandList.o \
	TrVMECommandList.o Tr1553CommandList.o
	ranlib libDataStructure.a

TrDecodePair.o: TrDecodePair.cc
	$(CC) $(CFLAGS) $(INCLUDE) TrDecodePair.cc

TrAFEInitialisationState.o: TrAFEInitialisationState.cc
	$(CC) $(CFLAGS) $(INCLUDE) TrAFEInitialisationState.cc

TrAFEBoardInitialisationState.o: TrAFEBoardInitialisationState.cc
	$(CC) $(CFLAGS) $(INCLUDE) TrAFEBoardInitialisationState.cc

TrCommandList.o: TrCommandList.cc
	$(CC) $(CFLAGS) $(INCLUDE) TrCommandList.cc
	
TrFPGACommandList.o: TrFPGACommandList.cc
	$(CC) $(CFLAGS) $(INCLUDE) TrFPGACommandList.cc

TrVMECommandList.o: TrVMECommandList.cc
	$(CC) $(CFLAGS) $(INCLUDE) TrVMECommandList.cc

Tr1553CommandList.o: Tr1553CommandList.cc
	$(CC) $(CFLAGS) $(INCLUDE) Tr1553CommandList.cc

TrTriPtInitialisationState.o: TrTriPtInitialisationState.cc
	$(CC) $(CFLAGS) $(INCLUDE) TrTriPtInitialisationState.cc	

TrBiasInitialisationState.o: TrBiasInitialisationState.cc
	$(CC) $(CFLAGS) $(INCLUDE) TrBiasInitialisationState.cc

TrTemperatureInitialisationState.o: TrTemperatureInitialisationState.cc
	$(CC) $(CFLAGS) $(INCLUDE) TrTemperatureInitialisationState.cc	

TrAnalogueInitialisationState.o: TrAnalogueInitialisationState.cc
	$(CC) $(CFLAGS) $(INCLUDE) TrAnalogueInitialisationState.cc	

TrDigitialInitialisationState.o: TrDigitalInitialisationState.cc
	$(CC) $(CFLAGS) $(INCLUDE) TrDigitalInitialisationState.cc

TrAFEObject.o: TrAFEObject.cc
	$(CC) $(CFLAGS) $(INCLUDE) TrAFEObject.cc

clean: 
	rm -rf *o DataStructure.a
