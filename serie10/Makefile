#file Makefile
#author Klaus Krapfenbauer MatrNr.:0926457
#brief Makefile for EProg TM serie10
#date 10.12.2012

CFLAGS=-g -ansi -pedantic -Wall #-D_XOPEN_SOURCE=700
LFLAGS=#-lm
CC=g++

all: bruchTest nameTest tictactoe


bruchTest: bruchTest.cpp Bruch.o
	$(CC) $(CFLAGS) -o bruchTest bruchTest.cpp $(LFLAGS) Bruch.o
	
nameTest: nameTest.cpp Name.o
	$(CC) $(CFLAGS) -o nameTest nameTest.cpp $(LFLAGS) Name.o
	
tictactoe: tictactoe.cpp Field.o
	$(CC) $(CFLAGS) -o tictactoe tictactoe.cpp $(LFLAGS) Field.o


Field.o: Field.cpp Field.hpp
	$(CC) -c $(CFLAGS) Field.cpp

Bruch.o: Bruch.cpp Bruch.hpp
	$(CC) -c $(CFLAGS) Bruch.cpp
	
Name.o: Name.cpp Name.hpp
	$(CC) -c $(CFLAGS) Name.cpp

clean:
	rm -f *.o bruchTest nameTest tictactoe

.PHONY: clean
