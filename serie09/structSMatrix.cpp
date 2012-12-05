#include "structSMatrix.hpp"


SMatrix* newSMatrix(int n) {
	return new SMatrix(n);
}

SMatrix* delSMatrix(SMatrix* matrix) {
	delete matrix;

	return NULL;
}

int getSMatrixN(SMatrix* matrix) {
	return matrix->n;
}
