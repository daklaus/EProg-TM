#include <stdio.h>
#include <stdlib.h>
#include "dynamicmatrix.h"
#include "dynamicvectors.h"
#include "dynamicintvectors.h"


void full2sparse(double* matrix, int m, int n, int** rowindex,
	int** colindex, double** value, int* N);

void sparse2full(int* rowindex, int* colindex, double* value,
	int N, double* matrix, int m, int n);

void mvmsparse(int* rowindex, int* colindex, double* value,
	int N, int m, int n, double* x, double* b);


int main(int argc, char** argv)
{
	int m=0, n=0, N=0;
	double* matrix = NULL;
	int* rowindex = NULL;
	int* colindex = NULL;
	double* value = NULL;
	double* x = NULL;
	double* b = NULL;

	printf("Input the number of rows of the matrix: ");
	scanf("%d", &m);
	printf("Input the number of columns of the matrix: ");
	scanf("%d", &n);
	m = m > 0 ? m : 0;
	n = n > 0 ? n : 0;
	printf("Input the matrix[%d][%d]:\n", m, n);
	matrix = scanmatrix(m, n);
	printf("Input the vector[%d]:\n", n);
	x = scanvector(n);

	printf("Matrix is:\n");
	printmatrix(matrix, m, n);

	full2sparse(matrix, m, n, &rowindex, &colindex, &value, &N);
	printf("Sparsed the matrix!\n");
	sparse2full(rowindex, colindex, value, N, matrix, m, n);
	printf("Re-fulled the matrix:\n");
	printmatrix(matrix, m, n);

	printf("Multiplicate...\n");
	b = mallocvector(m);
	mvmsparse(rowindex, colindex, value, N, m, n, x, b);
	
	printf("The matrix vector multiplication b = A*x:\n");
	printvector(b, m);

	matrix = freematrix(matrix);
	rowindex = freeintvector(rowindex);
	colindex = freeintvector(colindex);
	value = freevector(value);
	x = freevector(x);
	b = freevector(b);

	return EXIT_SUCCESS;
}

void full2sparse(double* matrix, int m, int n, int** rowindex,
	int** colindex, double** value, int* N) {
	int j, k;
	
	if(m < 0) m = 0;
	if(n < 0) n = 0;

	*N = 0;
	for(j=0; j<m; j++) {
		for(k=0; k<n; k++) {
			if(matrix[j+k*m] == 0)
				continue;
			*rowindex = reallocintvector(*rowindex, *N, *N+1);
			*colindex = reallocintvector(*colindex, *N, *N+1);
			*value = reallocvector(*value, *N, *N+1);
			(*N)++;
			(*rowindex)[(*N)-1] = j;
			(*colindex)[(*N)-1] = k;
			(*value)[(*N)-1] = matrix[j+k*m];
		}
	}
}

void sparse2full(int* rowindex, int* colindex, double* value,
	int N, double* matrix, int m, int n) {
	int i, j, k;
	
	if(m < 0) m = 0;
	if(n < 0) n = 0;
	if(N < 0) N = 0;

	for(i=0; i<N; i++) {
		j = rowindex[i];
		k = colindex[i];
		matrix[j+k*m] = value[i];
	}
}

void mvmsparse(int* rowindex, int* colindex, double* value,
	int N, int m, int n, double* x, double* b) {
	int i, j, k;
	
	if(m < 0) m = 0;
	if(n < 0) n = 0;
	if(N < 0) N = 0;

	for(i=0; i<N; i++) {
		j = rowindex[i];
		k = colindex[i];
		b[j] += value[i]*x[k];
	}
}
