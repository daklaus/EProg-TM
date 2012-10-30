#define DIM (118)

#include <stdio.h>
#include <stdlib.h>
#include <math.h>


void initialize(int x[], int n);

void printvector(int x[], int n);

void eratosthenes(int x[], int n);


int main(int argc, char** argv)
{
	int x[DIM]; /* Vector x element R^n */
	
	initialize(x, DIM);
	
	eratosthenes(x, DIM);

	printf("Sorted vector x[%d]:\n", DIM);
	printvector(x, DIM);

	return EXIT_SUCCESS;
}

void eratosthenes(int x[], int n)
{
	int i=0, j=0, nmax=n+2;
	double max=sqrt(nmax);

	for(i=0; i<max; i++) {
		if(x[i] == 0)
			continue;

		for(j=i+1; j<n; j++) {
			if(x[j] == 0)
				continue;
			if(x[j] % x[i] == 0) {
				x[j] = 0;
			}
		}
	}
}

void initialize(int x[], int n)
{
	int i = 0;
	for(i=0; i<n; i++) {
		x[i] = i+2;
	}
}

void printvector(int x[], int n)
{
	int i = 0;
	printf("(");
	for(i=0; i<n; i++)
	{
		if(x[i] == 0)
			continue;

		printf("%d", x[i]);
		if(i<n-1)
			printf(", ");
	}
	printf(")\n");
}
