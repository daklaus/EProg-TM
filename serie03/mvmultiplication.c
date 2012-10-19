#define DIM_M (2)
#define DIM_N (3)

#include <stdio.h>
#include <stdlib.h>
#include <math.h>


void scanvector(double x[], int n);

void printvector(double x[], int n);

void mvmultiplication(double a[], double x[], double b[], int m, int n);


int main(int argc, char** argv)
{
	/* 
	 * Matrix a element R^mn where A_jk = a_j+km of Matrix A
	 * element R^mxn
	 */
	double a[DIM_M*DIM_N];
	double x[DIM_N]; /* Vector x element R^n */
	double b[DIM_M]; /* Vector b element R^m */
	
	printf("Input matrix A[%d][%d]:\n", DIM_M, DIM_N);
	scanvector(a, DIM_M*DIM_N);
	printf("Input vector x[%d]:\n", DIM_N);
	scanvector(x, DIM_N);
	
	mvmultiplication(a, x, b, DIM_M, DIM_N);

	printf("Solved vector b[%d]:\n", DIM_M);
	printvector(b, DIM_M);

	return EXIT_SUCCESS;
}

/*
 * Solves the matrix-vector-multiplication b = A*x
 * where A is a matrix of R^mxn, the parameter a is
 * a flatened vector where A_jk = a_j+km and where
 * x is a vector of R^n and b is a vector of R^m.
 */
void mvmultiplication(double a[], double x[], double b[], int m, int n)
{
	int j=0, k=0;	

	for (j=0; j<m; j++) {
		b[j] = 0;
		for (k=0; k<n; k++) {
			b[j] = b[j] + a[j+k*m]*x[k];
		}
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
