#include "structSMatrix.hpp"


SMatrix* newSMatrix(int n) {
	return new SMatrix(n);
}

SMatrix* delSMatrix(SMatrix* matrix) {
	delete matrix->rowindex;
	delete matrix->colindex;
	delete matrix->values;
	delete matrix;

	return NULL;
}

int getSMatrixN(SMatrix* matrix) {
	return matrix->n;
}
