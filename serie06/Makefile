#file Makefile
#author Klaus Krapfenbauer MatrNr.:0926457
#brief Makefile for EProg TM serie06
#date 07.11.2012


CFLAGS=-g -ansi -pedantic -Wall -D_XOPEN_SOURCE=600
LFLAGS=-lm
CC=gcc


float2dec: float2dec.c
	$(CC) $(CFLAGS) -o float2dec float2dec.c $(LFLAGS)


clean:
	rm -f *.o float2dec

.PHONY: clean
