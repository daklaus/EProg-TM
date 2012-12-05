#include <stdio.h>
#include <stdlib.h>
#include "structMatrix.h"

int main(int argc, char** argv)
{
	int n=0, j, k;
	Matrix* matrix;

	/*
	 * Test 1
	 */
	printf("Input the number of rows and columns of the matrix: ");
	scanf("%d", &n);
	printf("Input the matrix[%d][%d]:\n", n, n);
	matrix = scanMatrix(n);
	
	printf("Printed matrix:\n");
	printMatrix(matrix);

	n = n > 0 ? n : 0;

	for(j=0, n=getMatrixDim(matrix); j<n; j++) {
		for(k=0; k<n; k++) {
			setMatrixEntry(matrix, j+k, j, k);
		}
	}
	
	printf("Changed matrix:\n");
	printMatrix(matrix);

	matrix = delMatrix(matrix);

	/*
	 * Test 2
	 */
	matrix = newMatrix(3, L);

	for(j=0, n=getMatrixDim(matrix); j<n; j++) {
		for(k=0; k<=j; k++) {
			setMatrixEntry(matrix, j+k+1, j, k);
		}
	}
	
	printf("Lower triangular matrix:\n");
	printMatrix(matrix);
	matrix = delMatrix(matrix);

	/*
	 * Test 3
	 */
	matrix = newMatrix(3, U);

	for(j=0, n=getMatrixDim(matrix); j<n; j++) {
		for(k=j; k<n; k++) {
			setMatrixEntry(matrix, j+k+1, j, k);
		}
	}
	
	printf("Upper triangular matrix:\n");
	printMatrix(matrix);
	matrix = delMatrix(matrix);

	return EXIT_SUCCESS;
}
