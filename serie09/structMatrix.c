#include "structMatrix.h"

static void fprintMatrix(FILE* stream, Matrix* matrix);

static void punknown(void);

static int getEntryDim(Matrix* matrix);



static void punknown(void) {
	perror("Unknown matrix type\n");
}

static int getEntryDim(Matrix* matrix) {
	int n = matrix->n;

	switch(matrix->type) {
	case F:
		return n*n;
		break;
	case U:
	case L:
		return n*(n+1)/2;
		break;
	default:
		return -1;
	}
}

Matrix* newMatrix(int n, MType type) {
	Matrix* matrix;
	int arraysize = 0;

	if(n < 0) n = 0;

	matrix = malloc(sizeof(Matrix));
	matrix->n = n;
	matrix->type = type;

	if((arraysize = getEntryDim(matrix)) == -1) {
		punknown();
		return NULL;
	}

	matrix->entry = calloc(arraysize, sizeof(double));

	return matrix;
}

Matrix* delMatrix(Matrix* matrix) {
	if(matrix == NULL)
		return NULL;
		
	if(matrix->entry != NULL)
		free(matrix->entry);

	free(matrix);
	return NULL;
}

int getMatrixDim(Matrix* matrix) {
	return matrix->n;
}

MType getMatrixType(Matrix* matrix) {
	return matrix->type;
}

double getMatrixEntry(Matrix* matrix, int j, int k) {
	int n = matrix->n;

	if(j < 0 || j >= n) {
		perror("Index j out of bounds");
		return -1;
	}
	if(k < 0 || k >= n) {
		perror("Index k out of bounds");
		return -1;
	}

	switch(matrix->type) {
	case F:
		return matrix->entry[j+k*n];
		break;
	case L:
		if(j < k) return 0;
		/*
		 *         -k^2 + (2n+1)k
		 * (j-k) + --------------
		 *               2
		 */
		return matrix->entry[(int) ((j-k) + ((-pow(k, 2)) + (2*n+1)*k) / 2)];
		break;
	case U:
		if(j > k) return 0;
		/*
		 *     k(k+1)
		 * j + ------
		 *       2
		 */
		return matrix->entry[j + (k*(k+1)) / 2];
		break;
	default:
		punknown();
		return -1;
		break;
	}
}

void setMatrixEntry(Matrix* matrix, double x, int j, int k) {
	int n = matrix->n;

	if(j < 0 || j >= n) {
		perror("Index j out of bounds");
		return;
	}
	if(k < 0 || k >= n) {
		perror("Index k out of bounds");
		return;
	}

	switch(matrix->type) {
	case F:
		matrix->entry[j+k*n] = x;
		break;
	case L:
		if(j < k) {
			fprintf(stderr, "Cannot set indices [%d][%d] because ", j, k);
			fprintf(stderr, "operating on a lower triangular matrix\n");
			return;
		}
		/*
		 *         -k^2 + (2n+1)k
		 * (j-k) + --------------
		 *               2
		 */
		matrix->entry[(int) ((j-k) + ((-pow(k, 2)) + (2*n+1)*k) / 2)] = x;
		break;
	case U:
		if(j > k) {
			fprintf(stderr, "Cannot set indices [%d][%d] because ", j, k);
			fprintf(stderr, "operating on an upper triangular matrix\n");
			return;
		}
		/*
		 *     k(k+1)
		 * j + ------
		 *       2
		 */
		matrix->entry[j + (k*(k+1)) / 2] = x;
		break;
	default:
		punknown();
		return;
		break;
	}
}

void saveMatrix(char* filepath, Matrix* matrix) {
	FILE* fp;
	if((fp = fopen(filepath, "w")) == NULL) {
		perror("Failed to open the file for writing\n");
		return;
	}
	fprintMatrix(fp, matrix);
	fclose(fp);
}

Matrix* loadMatrix(char* filepath, int n) {
	int j=0, k=0;
	FILE* fp;
	double tmp;
	Matrix* matrix;

	if((fp = fopen(filepath, "r")) == NULL) {
		perror("Failed to open the file for reading");
		return NULL;
	}

	matrix = newMatrix(n, F);

	j=0;
	for(j=0; j<n; j++) {
		for(k=0; k<n; k++) {
			if(fscanf(fp, "%lf", &tmp) != 1) {
				fprintf(stderr, "Error reading value %d from line %d of file", k+1, j+1);
				break;
			}
			setMatrixEntry(matrix, tmp, j, k);
		}
	}

	fclose(fp);

	return matrix;
}

Matrix* isUmatrix(Matrix* matrix) {
	int j, k, n;
	Matrix* ret;

	n = getMatrixDim(matrix);

	/* Check */
	for(j=1; j<n; j++) {
		for(k=0; k<j; k++) {
			if(getMatrixEntry(matrix, j, k) == 0)
				continue;
			printf("Matrix is not a U-matrix\n");
			return delMatrix(matrix);
		}
	}

	ret = newMatrix(n, U);

	for(j=0; j<n; j++) {
		for(k=j; k<n; k++) {
			setMatrixEntry(ret, getMatrixEntry(matrix, j, k), j, k);
		}
	}

	matrix = delMatrix(matrix);

	return ret;
}

Matrix* isLmatrix(Matrix* matrix) {
	int j, k, n;
	Matrix* ret;

	n = getMatrixDim(matrix);

	/* Check */
	for(j=0; j<n; j++) {
		for(k=j+1; k<n; k++) {
			if(getMatrixEntry(matrix, j, k) == 0)
				continue;
			printf("Matrix is not a L-matrix\n");
			return delMatrix(matrix);
		}
	}

	ret = newMatrix(n, L);

	for(j=0; j<n; j++) {
		for(k=0; k<=j; k++) {
			setMatrixEntry(ret, getMatrixEntry(matrix, j, k), j, k);
		}
	}

	matrix = delMatrix(matrix);

	return ret;
}

Matrix* scanMatrix(int n) {
	int j, k;
	Matrix* matrix;
	if(n < 0) n = 0;
	matrix = newMatrix(n, F);
	for (j=0; j<n; j++) {
		for (k=0; k<n; k++) {
			printf("matrix[%d][%d]: ", j, k);
			scanf("%lf", &matrix->entry[j+k*n]);
		}
	}
	return matrix;
}

static void fprintMatrix(FILE* stream, Matrix* matrix) {
	int j, k, n;
	n = matrix->n;
	if(matrix == NULL)
		return;
	for (j=0; j<n; j++) {
		for (k=0; k<n; k++) {
			fprintf(stream, "%6.2f", getMatrixEntry(matrix, j, k));
			if(k<n-1) fprintf(stream, " ");
		}
		fprintf(stream, "\n");
	}
}

void printMatrix(Matrix* matrix) {
	fprintMatrix(stdout, matrix);
}
