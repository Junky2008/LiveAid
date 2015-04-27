IDIR =.
CC=g++
CFLAGS=-std=c++11 -I$(IDIR) -I../Inc -I../Inc/mosquitto -lmosquittopp -L/usr/local/lib
TESTFLAGS=-lgtest -lpthread


main: mosquittoClient.o
	$(CC) ../Src/main.cpp ../Output/mosquittoClient.o -o ../Output/main $(CFLAGS)

test: mosquittoClient.o mosquittoTestClient.o
	$(CC) ../Test/UnitTest.cpp ../Output/mosquittoClient.o ../Output/mosquittoTestClient.o -o ../Output/UnitTest $(CFLAGS) $(TESTFLAGS)

mosquittoClient.o:
	$(CC) ../Src/mosquittoClient.cpp -c -o ../Output/mosquittoClient.o $(CFLAGS)

mosquittoTestClient.o:
	$(CC) ../Test/mosquittoTestClient.cpp -c -o ../Output/mosquittoTestClient.o $(CFLAGS) $(TESTFLAGS)

.PHONY: clean

all: main

clean:
	rm ../Output/*
