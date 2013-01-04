#file Makefile
#author Klaus Krapfenbauer MatrNr.:0926457
#brief Makefile for EProg TM serie10
#date 10.12.2012

CFLAGS=-g -ansi -pedantic -Wall #-D_XOPEN_SOURCE=700
LFLAGS=#-lm
CC=g++

all: personTest


personTest: personTest.cpp Student.o Arbeiter.o Person.o
	$(CC) $(CFLAGS) -o personTest personTest.cpp $(LFLAGS) Person.o Student.o Arbeiter.o
	
	
Person.o: Person.cpp Person.hpp
	$(CC) -c $(CFLAGS) Person.cpp

Student.o: Student.cpp Student.hpp
	$(CC) -c $(CFLAGS) Student.cpp

Arbeiter.o: Arbeiter.cpp Arbeiter.hpp
	$(CC) -c $(CFLAGS) Arbeiter.cpp
	

clean:
	rm -f *.o personTest

.PHONY: clean
