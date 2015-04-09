IDIR = .
CC=g++
CFLAGS=-I$(IDIR)


main:
	$(CC) main.cpp -o main $(CFLAGS)

.PHONY: clean

all: main

clean:
	rm main
