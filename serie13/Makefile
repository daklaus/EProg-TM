#file Makefile
#author Klaus Krapfenbauer MatrNr.:0926457
#brief Makefile for EProg TM serie12
#date 04.01.2013

CFLAGS=-g -ansi -pedantic -Wall #-D_XOPEN_SOURCE=700
LFLAGS=#-lm
CC=g++

all: squareMatrixTest spdMatrixTest binarySearch

	
squareMatrixTest: squareMatrixTest.cpp Matrix.o SquareMatrix.o
	$(CC) $(CFLAGS) -o squareMatrixTest squareMatrixTest.cpp $(LFLAGS) Matrix.o SquareMatrix.o
	
spdMatrixTest: spdMatrixTest.cpp Matrix.o SquareMatrix.o SymmMatrix.o SpdMatrix.o
	$(CC) $(CFLAGS) -o spdMatrixTest spdMatrixTest.cpp $(LFLAGS) Matrix.o SquareMatrix.o SymmMatrix.o SpdMatrix.o
	
binarySearch: binarySearch.cpp
	$(CC) $(CFLAGS) -o binarySearch binarySearch.cpp $(LFLAGS)

	
Matrix.o: Matrix.cpp Matrix.hpp
	$(CC) -c $(CFLAGS) Matrix.cpp
	
SquareMatrix.o: SquareMatrix.cpp SquareMatrix.hpp SymmMatrix.hpp Matrix.hpp 
	$(CC) -c $(CFLAGS) SquareMatrix.cpp
	
SymmMatrix.o: SymmMatrix.cpp SymmMatrix.hpp SquareMatrix.hpp Matrix.hpp
	$(CC) -c $(CFLAGS) SymmMatrix.cpp
	
SpdMatrix.o: SpdMatrix.cpp SpdMatrix.hpp SymmMatrix.hpp SquareMatrix.hpp
	$(CC) -c $(CFLAGS) SpdMatrix.cpp

clean:
	rm -f *.o squareMatrixTest spdMatrixTest binarySearch

.PHONY: clean
