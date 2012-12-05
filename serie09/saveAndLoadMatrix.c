#include <stdio.h>
#include <stdlib.h>
#include "structMatrix.h"

#define FILENAME ("matrix.txt")

int main(int argc, char** argv)
{
	int n=0, j, k, i;
	Matrix* matrix;

	printf("Input the number of rows and columns of the matrix: ");
	scanf("%d", &n);
	
	if(n<0) n=0;

	/*
	 * Test 1
	 */
	matrix = newMatrix(n, F);

	i=1;
	for(j=0; j<n; j++) {
		for(k=0; k<n; k++) {
			setMatrixEntry(matrix, i, j, k);
			i++;
		}
	}
	
	printf("F-Matrix before save:\n");
	printMatrix(matrix);

	saveMatrix(FILENAME, matrix);

	matrix = delMatrix(matrix);

	matrix = loadMatrix(FILENAME, n);

	printf("F-Matrix after load:\n");
	printMatrix(matrix);
	
	matrix = delMatrix(matrix);

	/*
	 * Test 2
	 */
	matrix = newMatrix(n, L);

	i=1;
	for(j=0; j<n; j++) {
		for(k=0; k<=j; k++) {
			setMatrixEntry(matrix, i, j, k);
			i++;
		}
	}
	
	printf("L-Matrix before save:\n");
	printMatrix(matrix);

	saveMatrix(FILENAME, matrix);

	matrix = delMatrix(matrix);

	matrix = loadMatrix(FILENAME, n);

	printf("L-Matrix after load:\n");
	printMatrix(matrix);

	matrix = isLmatrix(matrix);
	if(matrix == NULL)
		return EXIT_FAILURE;

	printf("L-Matrix conversion:\n");
	printMatrix(matrix);
	
	matrix = delMatrix(matrix);

	/*
	 * Test 3
	 */
	matrix = newMatrix(n, U);

	i=1;
	for(j=0; j<n; j++) {
		for(k=j; k<n; k++) {
			setMatrixEntry(matrix, i, j, k);
			i++;
		}
	}
	
	printf("U-Matrix before save:\n");
	printMatrix(matrix);

	saveMatrix(FILENAME, matrix);

	matrix = delMatrix(matrix);

	matrix = loadMatrix(FILENAME, n);

	printf("U-Matrix after load:\n");
	printMatrix(matrix);

	matrix = isUmatrix(matrix);
	if(matrix == NULL)
		return EXIT_FAILURE;

	printf("U-Matrix conversion:\n");
	printMatrix(matrix);
	
	matrix = delMatrix(matrix);

	return EXIT_SUCCESS;
}
