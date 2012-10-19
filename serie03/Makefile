#file Makefile
#author Klaus Krapfenbauer MatrNr.:0926457
#brief Makefile for EProg TM serie02
#date 12.10.2012


CFLAGS=-g -ansi -pedantic -Wall
LFLAGS=-lm
CC=gcc


geometricMean: geometricMean.c
	$(CC) $(CFLAGS) -o geometricMean geometricMean.c $(LFLAGS)

fibonacci: fibonacci.c
	$(CC) $(CFLAGS) -o fibonacci fibonacci.c $(LFLAGS)

mvmultiplication: mvmultiplication.c
	$(CC) $(CFLAGS) -o mvmultiplication mvmultiplication.c $(LFLAGS)

pol2cart: pol2cart.c
	$(CC) $(CFLAGS) -o pol2cart pol2cart.c $(LFLAGS)


clean:
	rm -f *.o geometricMean fibonacci mvmultiplication pol2cart

.PHONY: clean
