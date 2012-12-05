#include <stdio.h>
#include <stdlib.h>
#include "structMatrix.h"


void computeLU(Matrix* A, Matrix* L, Matrix* U);


int main(int argc, char** argv)
{
	int n=0;
	Matrix* a;
	Matrix* l;
	Matrix* u;

	printf("Input the number of rows and columns of the matrix: ");
	scanf("%d", &n);
	printf("Input the matrix[%d][%d]:\n", n, n);
	a = scanMatrix(n);
	
	printf("Matrix A:\n");
	printMatrix(a);

	n = getMatrixDim(a);
	l = newMatrix(n, L);
	u = newMatrix(n, U);

	computeLU(a, l, u);

	printf("Matrix L:\n");
	printMatrix(l);

	printf("Matrix U:\n");
	printMatrix(u);

	a = delMatrix(a);
	l = delMatrix(l);
	u = delMatrix(u);

	return EXIT_SUCCESS;
}

void computeLU(Matrix* a, Matrix* l, Matrix* u) {
	int n, i=0, k=0, j=0;
	double tmp=0;
	
	n = getMatrixDim(a);

	for(i=0; i<n; i++) {
		/* Set l_ii */
		setMatrixEntry(l, 1, i, i);
		/* Calculate u_ik */
		for(k=i; k<n; k++) {
			tmp = getMatrixEntry(a, i, k);
			for(j=0; j<=i-1; j++) {
				tmp -= getMatrixEntry(l, i, j) * getMatrixEntry(u, j, k);
			}
			setMatrixEntry(u, tmp, i, k);
		}
		/* Calculate l_ki */
		for(k=i+1; k<n; k++) {
			tmp = getMatrixEntry(a, k, i);
			for(j=0; j<=i-1; j++) {
				tmp -= getMatrixEntry(l, k, j) * getMatrixEntry(u, j, i);
			}
			tmp /= getMatrixEntry(u, i, i);
			setMatrixEntry(l, tmp, k, i);
		}
	}
}
