#file Makefile
#author Klaus Krapfenbauer MatrNr.:0926457
#brief Makefile for EProg TM serie03
#date 19.10.2012


CFLAGS=-g -ansi -pedantic -Wall
LFLAGS=-lm
CC=gcc


powN: powN.c
	$(CC) $(CFLAGS) -o powN powN.c $(LFLAGS)


clean:
	rm -f *.o powN

.PHONY: clean
