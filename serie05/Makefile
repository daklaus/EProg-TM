#file Makefile
#author Klaus Krapfenbauer MatrNr.:0926457
#brief Makefile for EProg TM serie03
#date 19.10.2012


CFLAGS=-g -ansi -pedantic -Wall -D_XOPEN_SOURCE=600
LFLAGS=-lm
CC=gcc


powN: powN.c
	$(CC) $(CFLAGS) -o powN powN.c $(LFLAGS)

diffpol: diffpol.c
	$(CC) $(CFLAGS) -o diffpol diffpol.c $(LFLAGS)

frobeniusnorm: frobeniusnorm.c
	$(CC) $(CFLAGS) -o frobeniusnorm frobeniusnorm.c $(LFLAGS)

sin: sin.c
	$(CC) $(CFLAGS) -o sin sin.c $(LFLAGS)


clean:
	rm -f *.o powN diffpol frobeniusnorm sin

.PHONY: clean
