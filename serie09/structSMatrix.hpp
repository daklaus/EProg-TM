#ifndef STRUCT_SMATRIX
#define STRUCT_SMATRIX
#include <iostream>
#include <vector>
using namespace std;

struct SMatrix {
	int n;
	vector<int>* rowindex;
	vector<int>* colindex;
	vector<double>* value;

	SMatrix (int initN);
};

/*
 * Memory allocation and initialization of
 * a dynamic double matrix of length n by n
 */
SMatrix* newSMatrix(int n);

/*
 * Free a dynamic matrix of arbitrary length and
 * set the pointer to NULL
 */
SMatrix* delSMatrix(SMatrix* matrix);

/*
 * Get the dimension N of the matrix
 */
int getMatrixN(SMatrix* matrix);

#endif
