#file Makefile
#author Klaus Krapfenbauer MatrNr.:0926457
#brief Makefile for EProg TM serie12
#date 04.01.2013

CFLAGS=-g -ansi -pedantic -Wall #-D_XOPEN_SOURCE=700
LFLAGS=#-lm
CC=g++

all: personTest stoppuhrTest squareMatrixTest


personTest: personTest.cpp Student.o Arbeiter.o Person.o
	$(CC) $(CFLAGS) -o personTest personTest.cpp $(LFLAGS) Person.o Student.o Arbeiter.o

stoppuhrTest: stoppuhrTest.cpp Stoppuhr.o
	$(CC) $(CFLAGS) -o stoppuhrTest stoppuhrTest.cpp $(LFLAGS) Stoppuhr.o
	
squareMatrixTest: squareMatrixTest.cpp Matrix.o SquareMatrix.o
	$(CC) $(CFLAGS) -o squareMatrixTest squareMatrixTest.cpp $(LFLAGS) Matrix.o SquareMatrix.o
	
	
Person.o: Person.cpp Person.hpp
	$(CC) -c $(CFLAGS) Person.cpp

Student.o: Student.cpp Student.hpp Person.hpp
	$(CC) -c $(CFLAGS) Student.cpp

Arbeiter.o: Arbeiter.cpp Arbeiter.hpp Person.hpp
	$(CC) -c $(CFLAGS) Arbeiter.cpp

Stoppuhr.o: Stoppuhr.cpp Stoppuhr.hpp
	$(CC) -c $(CFLAGS) Stoppuhr.cpp
	
Matrix.o: Matrix.cpp Matrix.hpp
	$(CC) -c $(CFLAGS) Matrix.cpp
	
SquareMatrix.o: SquareMatrix.cpp SquareMatrix.hpp Matrix.hpp
	$(CC) -c $(CFLAGS) SquareMatrix.cpp
	

clean:
	rm -f *.o personTest stoppuhrTest squareMatrixTest

.PHONY: clean
