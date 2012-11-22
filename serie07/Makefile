#file Makefile
#author Klaus Krapfenbauer MatrNr.:0926457
#brief Makefile for EProg TM serie07
#date 19.11.2012


CFLAGS=-g -ansi -pedantic -Wall -D_XOPEN_SOURCE=600
LFLAGS=-lm
CC=gcc


unique: unique.c
	$(CC) $(CFLAGS) -o unique unique.c $(LFLAGS)

dynamicvectors.o: dynamicvectors.c dynamicvectors.h
	$(CC) -c $(CFLAGS) dynamicvectors.c

dynamicintvectors.o: dynamicintvectors.c dynamicintvectors.h
	$(CC) -c $(CFLAGS) dynamicintvectors.c

dynamicmatrix.o: dynamicmatrix.c dynamicmatrix.h
	$(CC) -c $(CFLAGS) dynamicmatrix.c

testm: testm.c dynamicmatrix.o
	$(CC) $(CFLAGS) -o testm testm.c $(LFLAGS) dynamicmatrix.o

testv: testv.c dynamicvectors.o
	$(CC) $(CFLAGS) -o testv testv.c $(LFLAGS) dynamicvectors.o

sparse: sparse.c dynamicvectors.o dynamicmatrix.o dynamicintvectors.o
	$(CC) $(CFLAGS) -o sparse sparse.c $(LFLAGS) dynamicvectors.o dynamicmatrix.o dynamicintvectors.o


clean:
	rm -f *.o unique testm testv sparse

.PHONY: clean
