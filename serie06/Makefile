#file Makefile
#author Klaus Krapfenbauer MatrNr.:0926457
#brief Makefile for EProg TM serie06
#date 07.11.2012


CFLAGS=-g -ansi -pedantic -Wall -D_XOPEN_SOURCE=600
LFLAGS=-lm
CC=gcc


float2dec: float2dec.c
	$(CC) $(CFLAGS) -o float2dec float2dec.c $(LFLAGS)

swap: swap.c
	$(CC) $(CFLAGS) -o swap swap.c $(LFLAGS)

minmax2: minmax2.c
	$(CC) $(CFLAGS) -o minmax2 minmax2.c $(LFLAGS)

dec2float: dec2float.c
	$(CC) $(CFLAGS) -o dec2float dec2float.c $(LFLAGS)


clean:
	rm -f *.o float2dec swap minmax2 dec2float

.PHONY: clean
