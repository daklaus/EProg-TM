#file Makefile
#author Klaus Krapfenbauer MatrNr.:0926457
#brief Makefile for EProg TM serie10
#date 10.12.2012

CFLAGS=-g -ansi -pedantic -Wall #-D_XOPEN_SOURCE=700
LFLAGS=#-lm
CC=g++

all: Person.o Student.o Arbeiter.o


bruchTest: bruchTest.cpp Bruch.o
	$(CC) $(CFLAGS) -o bruchTest bruchTest.cpp $(LFLAGS) Bruch.o
	
realVectorTest: realVectorTest.cpp RealVector.o
	$(CC) $(CFLAGS) -o realVectorTest realVectorTest.cpp $(LFLAGS) RealVector.o
	
frobeniusnorm: frobeniusnorm.cpp RealVector.o
	$(CC) $(CFLAGS) -o frobeniusnorm frobeniusnorm.cpp $(LFLAGS) RealVector.o
	
	
Person.o: Person.cpp Person.hpp
	$(CC) -c $(CFLAGS) Person.cpp

Student.o: Student.cpp Student.hpp
	$(CC) -c $(CFLAGS) Student.cpp

Arbeiter.o: Arbeiter.cpp Arbeiter.hpp
	$(CC) -c $(CFLAGS) Arbeiter.cpp
	

clean:
	rm -f *.o 

.PHONY: clean
