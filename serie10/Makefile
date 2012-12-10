#file Makefile
#author Klaus Krapfenbauer MatrNr.:0926457
#brief Makefile for EProg TM serie10
#date 10.12.2012

CFLAGS=-g -ansi -pedantic -Wall #-D_XOPEN_SOURCE=700
LFLAGS=#-lm
CC=g++

all: Bruch.o bruchTest

Bruch.o: Bruch.cpp Bruch.hpp
	$(CC) -c $(CFLAGS) Bruch.cpp

bruchTest: bruchTest.cpp Bruch.o
	$(CC) $(CFLAGS) -o bruchTest bruchTest.cpp $(LFLAGS) Bruch.o

clean:
	rm -f *.o bruchTest

.PHONY: clean
