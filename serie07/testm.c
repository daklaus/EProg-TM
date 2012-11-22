#include <stdio.h>
#include <stdlib.h>
#include "dynamicmatrix.h"

int main(int argc, char** argv)
{
	int m=0, n=0, j, k, jx, kx;
	double* matrix;

	printf("Input the number of rows of the matrix: ");
	scanf("%d", &m);
	printf("Input the number of columns of the matrix: ");
	scanf("%d", &n);
	printf("Input the matrix[%d][%d]:\n", m, n);
	matrix = scanmatrix(m, n);
	
	printf("Printed matrix:\n");
	printmatrix(matrix, m, n);

	m = m > 0 ? m : 0;
	n = n > 0 ? n : 0;

	matrix = reallocmatrix(matrix, m, n, m+3, n+3);
	m += 3;
	n += 3;
	printf("Upsized matrix:\n");
	printmatrix(matrix, m, n);

	jx=m-2;
	kx=n-2;

	for(j=0; j<m; j++) {
		matrix[j+kx*m] = j;
	}
	for(k=0; k<n; k++) {
		matrix[jx+k*m] = k;
	}

	printf("Changed matrix:\n");
	printmatrix(matrix, m, n);

	matrix = cutOffRowJ(matrix, m--, n, jx);
	printf("Cut off row %d:\n", jx);
	printmatrix(matrix, m, n);

	matrix = cutOffColK(matrix, m, n--, kx);
	printf("Cut off col %d:\n", kx);
	printmatrix(matrix, m, n);

	matrix = reallocmatrix(matrix, m, n, m-2, n-2);
	m -= 2;
	n -= 2;
	printf("Downsized matrix:\n");
	printmatrix(matrix, m, n);

	matrix = freematrix(matrix);

	return EXIT_SUCCESS;
}
