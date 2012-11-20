#file Makefile
#author Klaus Krapfenbauer MatrNr.:0926457
#brief Makefile for EProg TM serie06
#date 07.11.2012


CFLAGS=-g -ansi -pedantic -Wall -D_XOPEN_SOURCE=600
LFLAGS=-lm
CC=gcc


unique: unique.c
	$(CC) $(CFLAGS) -o unique unique.c $(LFLAGS)

swap: swap.c
	$(CC) $(CFLAGS) -o swap swap.c $(LFLAGS)


clean:
	rm -f *.o unique

.PHONY: clean
