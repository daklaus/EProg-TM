#ifndef STRUCT_SMATRIX
#define STRUCT_SMATRIX
#include <iostream>
#include <vector>
using namespace std;

struct SMatrix {
	SMatrix (int initM, int initN) {
		m = initM < 0 ? 0 : initM;
		n = initN < 0 ? 0 : initN;
		entry = vector<double>(m*n);
	}
	int m;
	int n;
	vector<double> entry;
};

/*
 * Memory allocation and initialization of
 * a dynamic double matrix of length m by n
 */
SMatrix* newSMatrix(int m, int n);

/*
 * Free a dynamic matrix of arbitrary length and
 * set the pointer to NULL
 */
SMatrix* delSMatrix(SMatrix* matrix);

/*
 * Get the dimension M of the matrix
 */
int getMatrixM(SMatrix* matrix);

/*
 * Get the dimension N of the matrix
 */
int getMatrixN(SMatrix* matrix);

#endif
