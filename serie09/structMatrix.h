#ifndef STRUCT_MATRIX
#define STRUCT_MATRIX
#include <stdio.h>
#include <stdlib.h>
#include <math.h>

typedef enum {
	F,
	U,
	L
} MType;

typedef struct {
	int n;
	double* entry;
	MType type; /* F = full, L = lower triangular, U = upper triangular */
} Matrix;

/*
 * Memory allocation and initialization of
 * a dynamic double matrix of length n by n
 */
Matrix* newMatrix(int n, MType type);

/*
 * Free a dynamic matrix of arbitrary length and
 * set the pointer to NULL
 */
Matrix* delMatrix(Matrix* matrix);

/*
 * Get the dimension of the matrix
 */
int getMatrixDim(Matrix* matrix);

/*
 * Get the type of the matrix.
 */
MType getMatrixType(Matrix* matrix);

/*
 * Get an entry of the matrix
 */
double getMatrixEntry(Matrix* matrix, int j, int k);

/*
 * Sets an entry of the matrix
 */
void setMatrixEntry(Matrix* matrix, double x, int j, int k);

/*
 * Save a matrix to a file
 */
void saveMatrix(char* filepath, Matrix* matrix);

/*
 * Load a matrix from a file
 */
Matrix* loadMatrix(char* filepath, int n);

/*
 * Convert a matrix (stored as a full matrix)
 * to an upper triangular matrix (if convertible)
 */
Matrix* isUmatrix(Matrix* matrix);

/*
 * Convert a matrix (stored as a full matrix)
 * to a lower triangular matrix (if convertible)
 */
Matrix* isLmatrix(Matrix* matrix);

/*
 * Allocate dynamic double matrix of length m by n
 * and read entries from keyboard
 */
Matrix* scanMatrix(int n);

/*
 * Print dynamic double matrix of length m by n to
 * shell
 */
void printMatrix(Matrix* matrix);

#endif
