#define DIM (5)

#include <stdio.h>
#include <stdlib.h>
#include <math.h>


void scanvector(double x[], int n);

void printvector(double x[], int n);

void diffpol(double x[], int n);


int main(int argc, char** argv)
{
	double x[DIM];
	
	printf("Input the vector of the coefficients x[%d]:\n", DIM;
	scanvector(x, DIM);
	
	diffpol(x, DIM);

	printf("The vector of the derived coefficients x'[%d]:\n", DIM);
	printvector(x, DIM);

	return EXIT_SUCCESS;
}

/*
 * x'(i) = i*a_i
 */
void diffpol(double x[], int n)
{
	int i=0;
	for(; i<n; i++) {
		x[i] = i * x[i];
	}
}

void scanvector(double x[], int n)
{
	int i = 0;
	for(i=0; i<n; i++)
	{
		x[i] = 0;
		printf("%d: ", i);
		scanf("%lf", &x[i]);
	}
}

void printvector(double x[], int n)
{
	int i = 0;
	printf("(");
	for(i=0; i<n; i++)
	{
		printf("%.2f", x[i]);
		if(i<n-1)
			printf(", ");
	}
	printf(")\n");
}
