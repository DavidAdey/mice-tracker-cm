CC=g++
CFLAGS=-c -v
SRC=/home/adey/MICE/Tracker/mice-tracker-cm
INCLUDE=-I $(SRC)/DataStructure/ -I $(SRC)/Base/

all: Data 	

Data: TrBase.o TrLogger.o 
	ar -rcv libBase.a TrBase.o TrLogger.o
	ranlib libBase.a

main.o: main.cc
	$(CC) $(CFLAGS) main.cc

TrBase.o: TrBase.cc
	$(CC) $(CFLAGS) $(INCLUDE) TrBase.cc

TrLogger.o: TrLogger.cc
	$(CC) $(CFLAGS) $(INCLUDE) TrLogger.cc

clean: 
	rm -rf *o Data
