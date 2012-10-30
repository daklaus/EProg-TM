#file Makefile
#author Klaus Krapfenbauer MatrNr.:0926457
#brief Makefile for EProg TM serie03
#date 19.10.2012


CFLAGS=-g -ansi -pedantic -Wall
LFLAGS=-lm
CC=gcc


bubblesort: bubblesort.c
	$(CC) $(CFLAGS) -o bubblesort bubblesort.c $(LFLAGS)

pnorm: pnorm.c
	$(CC) $(CFLAGS) -o pnorm pnorm.c $(LFLAGS)

eratosthenes: eratosthenes.c
	$(CC) $(CFLAGS) -o eratosthenes eratosthenes.c $(LFLAGS)

matmult: matmult.c
	$(CC) $(CFLAGS) -o matmult matmult.c $(LFLAGS)


clean:
	rm -f *.o bubblesort pnorm eratosthenes matmult

.PHONY: clean
