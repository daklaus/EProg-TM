#file Makefile
#author Klaus Krapfenbauer MatrNr.:0926457
#brief Makefile for EProg TM serie01
#date 07.10.2012


CFLAGS=-g -ansi -pedantic -Wall
LFLAGS=-lm
CC=gcc


kreis: kreis.c
	$(CC) $(FLAGS) -o kreis kreis.c $(LFLAGS)

sortMe: sortMe.c
	$(CC) $(FLAGS) -o sortMe sortMe.c $(LFLAGS)

folgenglied: folgenglied.c
	$(CC) $(FLAGS) -o folgenglied folgenglied.c $(LFLAGS)

kugel: kugel.c
	$(CC) $(FLAGS) -o kugel kugel.c $(LFLAGS)

a1: a1.c
	$(CC) $(FLAGS) -o a1 a1.c $(LFLAGS)


clean:
	rm -f *.o kreis sortMe folgenglied kugel a1

.PHONY: clean
