#include "structSMatrix.hpp"


SMatrix* newSMatrix(int m, int n) {
	return new SMatrix(m, n);
}

SMatrix* delSMatrix(SMatrix* matrix) {
	delete matrix;

	return NULL;
}

int getSMatrixM(SMatrix* matrix) {
	return matrix->m;
}

int getSMatrixN(SMatrix* matrix) {
	return matrix->n;
}
