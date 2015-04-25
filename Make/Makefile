IDIR =.
CC=g++
CFLAGS=-I$(IDIR) -I../Inc
TESTFLAGS=-lgtest -lpthread


main:
	$(CC) ../Src/main.cpp -o ../Output/main $(CFLAGS)

test:
	$(CC) ../Test/UnitTest.cpp -o ../Output/UnitTest $(CFLAGS) $(TESTFLAGS)

.PHONY: clean

all: main

clean:
	rm ../Output/*
