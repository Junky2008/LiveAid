IDIR = .
CC=g++
CFLAGS=-I$(IDIR)


main:
	gcc main.cpp -o main $(CFLAGS)

.PHONY: clean

all:
	main

clean:
	rm main
