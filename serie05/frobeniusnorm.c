#define DIM_M (3)
#define DIM_N (2)

#include <stdio.h>
#include <stdlib.h>
#include <math.h>


void scanvector(double x[], int n);

void printvector(double x[], int n);

double frobeniusnorm(double a[], int m, int n);


int main(int argc, char** argv)
{
	/* 
	 * Matrix a element R^mn where A_jk = a_j+k*m of Matrix A
	 * element R^mxn
	 */
	double a[DIM_M*DIM_N];
	
	printf("Input matrix A[%d][%d]:\n", DIM_M, DIM_N);
	scanvector(a, DIM_M*DIM_N);
	
	printf("Frobeniusnorm of A is: %.2f\n", frobeniusnorm(a, DIM_M, DIM_N));

	return EXIT_SUCCESS;
}

/*
 * Calculates the frobeniusnorm
 * where A is a matrix of R^mxn, the parameter a is
 * a flatened matrix where A_jk = a_j+km.
 */
double frobeniusnorm(double a[], int m, int n)
{
	double sum=0;
	int i=0, max=m*n;

	for (i=0; i<max; i++) {
		sum += a[i]*a[i];
	}

	return sum;
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
