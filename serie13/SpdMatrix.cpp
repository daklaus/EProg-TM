/*
 * SpdMatrix.cpp
 *
 *  Created on: Jan 15, 2013
 *      Author: klaus
 */

#include "SpdMatrix.hpp"

/*
 * Member functions
 */
SpdMatrix::SpdMatrix(int n, int init) :
	SymmMatrix(n, init) {
}

SpdMatrix::~SpdMatrix() {
}

SquareMatrix SpdMatrix::chol() const {
	SquareMatrix l(*this);
	double sum;
	int i, j, k, n(getN());

	for (i = 0; i < n; ++i) {
		for (j = 0; j < i; ++j) {
			sum = l.getEntry(i, j);
			for (k = 0; k < j; ++k) {
				sum = sum - l.getEntry(i, k) * l.getEntry(j, k);
			}
			l.setEntry(i, j, sum / l.getEntry(j, j));
		}
		sum = l.getEntry(i, i);
		for (k = 0; k < i; ++k) {
			sum = sum - l.getEntry(i, k) * l.getEntry(i, k);
		}
		if (sum > 0) {
			// Summe ist positiv
			l.setEntry(i, i, sqrt(sum));
		} else {
			// A ist nicht positiv definit
			throw logic_error("The matrix is not positive definite");
		}
	}

	for (i = 0; i < n - 1; ++i) {
		for (j = i + 1; j < n; ++j) {
			l.setEntry(i, j, 0);
		}
	}

	return l;
}
