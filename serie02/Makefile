#file Makefile
#author Klaus Krapfenbauer MatrNr.:0926457
#brief Makefile for EProg TM serie02
#date 12.10.2012


CFLAGS=-g -ansi -pedantic -Wall
LFLAGS=-lm
CC=gcc


myabs: myabs.c
	$(CC) $(CFLAGS) -o myabs myabs.c $(LFLAGS)

bruch: bruch.c
	$(CC) $(CFLAGS) -o bruch bruch.c $(LFLAGS)

evalpol: evalpol.c
	$(CC) $(CFLAGS) -o evalpol evalpol.c $(LFLAGS)

solver: solver.c
	$(CC) $(CFLAGS) -o solver solver.c $(LFLAGS)

teiler: teiler.c
	$(CC) $(CFLAGS) -o teiler teiler.c $(LFLAGS)

punkte: punkte.c
	$(CC) $(CFLAGS) -o punkte punkte.c $(LFLAGS)

fibonacciRek: fibonacciRek.c
	$(CC) $(CFLAGS) -o fibonacciRek fibonacciRek.c $(LFLAGS)


clean:
	rm -f *.o myabs bruch evalpol solver teiler punkte fibonacciRek

.PHONY: clean
