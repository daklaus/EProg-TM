#file Makefile
#author Klaus Krapfenbauer MatrNr.:0926457
#brief Makefile for EProg TM serie09
#date 04.12.2012


CFLAGS=-g -ansi -pedantic -Wall -D_XOPEN_SOURCE=700
LFLAGS=-lm
CC=gcc


structMatrix.o: structMatrix.c structMatrix.h
	$(CC) -c $(CFLAGS) structMatrix.c

test1: test1.c structMatrix.o
	$(CC) $(CFLAGS) -o test1 test1.c $(LFLAGS) structMatrix.o

computeLU: computeLU.c structMatrix.o
	$(CC) $(CFLAGS) -o computeLU computeLU.c $(LFLAGS) structMatrix.o

saveAndLoadMatrix: saveAndLoadMatrix.c structMatrix.o
	$(CC) $(CFLAGS) -o saveAndLoadMatrix saveAndLoadMatrix.c $(LFLAGS) structMatrix.o

structSMatrix.o: structSMatrix.cpp structSMatrix.hpp
	$(CC) -c $(CFLAGS) structSMatrix.cpp


clean:
	rm -f *.o test1 computeLU saveAndLoadMatrix matrix.txt

.PHONY: clean
