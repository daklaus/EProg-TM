#include "structSMatrix.hpp"

SMatrix::SMatrix (int initN) {
	n = initN < 0 ? 0 : initN;
	rowindex = new vector<int>();
	colindex = new vector<int>();
	value = new vector<double>();
}

SMatrix* newSMatrix(int n) {
	return new SMatrix(n);
}

SMatrix* delSMatrix(SMatrix* matrix) {
	delete matrix->rowindex;
	delete matrix->colindex;
	delete matrix->value;
	delete matrix;

	return NULL;
}

int getSMatrixN(SMatrix* matrix) {
	return matrix->n;
}
