#define MAXGUESS (3)

#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <time.h>


int main(int argc, char** argv)
{
	int rnr=0, i=0, x=0;

	srand((unsigned) time(NULL));
	rnr = (int) (16.*rand()/(RAND_MAX+1.));

	for(i=0; i<MAXGUESS; i++)
	{
		printf("%dter Rateversuch: ", i+1);
		scanf("%d", &x);

		if(x == rnr) {
			printf("Richtig!\n");
			i = MAXGUESS;
		} else if(x < rnr)
			printf("Zu niedrig\n");
		else
			printf("Zu hoch\n");

		if(i == MAXGUESS-1 && x != rnr)
			printf("Zufallszahl war %d\n", rnr);
	}

	return EXIT_SUCCESS;
}
