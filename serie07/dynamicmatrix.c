#include <stdio.h>
#include <stdlib.h>
#include "dynamicmatrix.h"


double* mallocmatrix(int m, int n) {
	if(m < 0) m = 0;
	if(n < 0) n = 0;
	return calloc(m*n, sizeof(double));
}

double* freematrix(double* matrix) {
	if(matrix != NULL)
		free(matrix);
	return NULL;
}

double* reallocmatrix(double* matrix, int m, int n, int mnew, int nnew) {
	int j, k, copyboundM, copyboundN;
	double* newmatrix;

	if(m < 0) m = 0;
	if(n < 0) n = 0;
	if(mnew < 0) mnew = 0;
	if(mnew < 0) nnew = 0;

	newmatrix = mallocmatrix(mnew, nnew);

	copyboundM = mnew < m ? mnew : m;
	copyboundN = nnew < n ? nnew : n;
	for(j=0; j<copyboundM; j++) {
		for(k=0; k<copyboundN; k++) {
			newmatrix[j+mnew*k] = matrix[j+m*k];
		}
	}
	
	free(matrix);

	return newmatrix;
}

double* scanmatrix(int m, int n) {
	int j, k;
	double* matrix;
	if(m < 0) m = 0;
	if(n < 0) n = 0;
	matrix = mallocmatrix(m, n);
	for (j=0; j<m; j++) {
		for (k=0; k<n; k++) {
			printf("matrix[%d][%d]: ", j, k);
			scanf("%lf", &matrix[j+k*m]);
		}
	}
	return matrix;
}

void printmatrix(double* matrix, int m, int n) {
	int j, k;
	if(matrix == NULL)
		return;
	for (j=0; j<m; j++) {
		for (k=0; k<n; k++) {
			printf("%6.2f", matrix[j+k*m]);
			if(k<n-1) printf(" ");
		}
		printf("\n");
	}
}

double* cutOffRowJ(double* matrix, int m, int n, int jx) {
	int j, k, mnew;
	double* newmatrix;

	if(m < 0) m = 0;
	if(n < 0) n = 0;
	mnew = m > 1 ? m-1 : 0;

	newmatrix = mallocmatrix(mnew, n);

	for(j=0; j<m; j++) {
		if(j < jx) {
			for(k=0; k<n; k++) {
				newmatrix[j+mnew*k] = matrix[j+m*k];
			}
		} else if(j > jx) {
			for(k=0; k<n; k++) {
				newmatrix[j-1+mnew*k] = matrix[j+m*k];
			}
		}
	}
	
	free(matrix);

	return newmatrix;
}

double* cutOffColK(double* matrix, int m, int n, int kx) {
	int j, k, nnew;
	double* newmatrix;

	if(m < 0) m = 0;
	if(n < 0) n = 0;
	nnew = n > 1 ? n-1 : 0;

	newmatrix = mallocmatrix(m, nnew);

	for(j=0; j<m; j++) {
		for(k=0; k<n; k++) {
			if(k < kx) {
				newmatrix[j+m*k] = matrix[j+m*k];
			} else if(k > kx) {
				newmatrix[j+m*(k-1)] = matrix[j+m*k];
			}
		}
	}
	
	free(matrix);

	return newmatrix;
}
