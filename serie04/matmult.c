#define DIM_M (3)
#define DIM_N (3)
#define DIM_O (3)

#include <stdio.h>
#include <stdlib.h>
#include <math.h>


void scanvector(double x[], int n);

void printvector(double x[], int n);

void matmult(double a[], double b[], double c[], int m, int n, int o);


int main(int argc, char** argv)
{
	/* 
	 * Matrix a element R^mn where A_jk = a_j+k*m of Matrix A
	 * element R^mxn
	 */
	double a[DIM_M*DIM_N];
	double b[DIM_N*DIM_O];
	double c[DIM_M*DIM_O];
	
	printf("Input matrix A[%d][%d]:\n", DIM_M, DIM_N);
	scanvector(a, DIM_M*DIM_N);
	printf("Input matrix B[%d][%d]:\n", DIM_N, DIM_O);
	scanvector(b, DIM_N*DIM_O);
	
	matmult(a, b, c, DIM_M, DIM_N, DIM_O);

	printf("Solved matrix C[%d][%d]:\n", DIM_M, DIM_O);
	printvector(c, DIM_M*DIM_O);

	return EXIT_SUCCESS;
}

/*
 * Solves the matrix-matrix-multiplication C = A*B
 * where A is a matrix of R^mxn, the parameter a is
 * a flatened matrix where A_jk = a_j+km and where
 * b is a flatened matrix of R^nxo and c is a matrix 
 * of R^mxo.
 */
void matmult(double a[], double b[], double c[], int m, int n, int o)
{
	int i=0, j=0, k=0;

	for (i=0; i<m; i++) {
		for (j=0; j<o; j++) {
			c[i+j*m] = 0;
			for (k=0; k<n; k++) {
				c[i+j*m] += a[i+k*m]*b[k+j*n];
			}
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
