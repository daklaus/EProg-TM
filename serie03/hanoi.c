#define MAXGUESS (3)

#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <time.h>


void hanoi(int m, int i, int j, int k);


int main(int argc, char** argv)
{
	int n=0;

	printf("n: ");
	scanf("%d", &n);

	hanoi(n, 1, 3, 2);

	return EXIT_SUCCESS;
}

void hanoi(int m, int i, int j, int k)
{
	if(m > 1)
		hanoi(m-1, i, k, j);
	printf("Scheibe %d wandert vom %d. zum %d. Pfosten\n", m, i, j);
	if(m > 1)
		hanoi(m-1, k, j, i);
}
