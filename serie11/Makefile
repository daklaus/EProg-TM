#file Makefile
#author Klaus Krapfenbauer MatrNr.:0926457
#brief Makefile for EProg TM serie11
#date 10.12.2012

CFLAGS=-g -ansi -pedantic -Wall #-D_XOPEN_SOURCE=700
LFLAGS=#-lm
CC=g++

all: bruchTest realVectorTest frobeniusnorm


bruchTest: bruchTest.cpp Bruch.o
	$(CC) $(CFLAGS) -o bruchTest bruchTest.cpp $(LFLAGS) Bruch.o
	
realVectorTest: realVectorTest.cpp RealVector.o
	$(CC) $(CFLAGS) -o realVectorTest realVectorTest.cpp $(LFLAGS) RealVector.o
	
frobeniusnorm: frobeniusnorm.cpp RealVector.o
	$(CC) $(CFLAGS) -o frobeniusnorm frobeniusnorm.cpp $(LFLAGS) RealVector.o
	
	
Bruch.o: Bruch.cpp Bruch.hpp
	$(CC) -c $(CFLAGS) Bruch.cpp
	
RealVector.o: RealVector.cpp RealVector.hpp
	$(CC) -c $(CFLAGS) RealVector.cpp
	

clean:
	rm -f *.o bruchTest realVectorTest frobeniusnorm

.PHONY: clean
