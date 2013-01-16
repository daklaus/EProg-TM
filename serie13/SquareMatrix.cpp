/*
 * SquareMatrix.cpp
 *
 *  Created on: Jan 6, 2013
 *      Author: klaus
 */

#include "SquareMatrix.hpp"

/*
 * Member functions
 */
SquareMatrix::SquareMatrix(int n, int init) :
	Matrix(n, n, init) {
}

SquareMatrix::SquareMatrix(const SymmMatrix& other) :
	Matrix(other.getN(), other.getN(), 0) {
	int i, j, n(other.getN());

	for (i = 0; i < n; ++i) {
		for (j = 0; j < n; ++j) {
			this->setEntry(i, j, other.getEntry(i, j));
		}
	}
}

SquareMatrix::~SquareMatrix() {
}

SquareMatrix SquareMatrix::computeLU() const {
	int n(getN());
	SquareMatrix lu(n, 0);
	int i, k, j;
	double tmp;

	for (i = 0; i < n; i++) {
		/* Set l_ii */
		/*setMatrixEntry(l, 1, i, i);*/

		/* Calculate u_ik */
		for (k = i; k < n; k++) {
			tmp = getEntry(i, k);
			for (j = 0; j < i; j++) {
				tmp -= lu.getEntry(i, j) * lu.getEntry(j, k);
			}
			lu.setEntry(i, k, tmp);
		}

		/* Calculate l_ki */
		for (k = i + 1; k < n; k++) {
			tmp = getEntry(k, i);
			for (j = 0; j < i; j++) {
				tmp -= lu.getEntry(k, j) * lu.getEntry(j, i);
			}
			tmp /= lu.getEntry(i, i);
			lu.setEntry(k, i, tmp);
		}
	}

	return lu;
}

double SquareMatrix::computeDet() const {
	throw logic_error("Method not implemented");
	return 0;
}
