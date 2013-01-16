/*
 * SymmMatrix.cpp
 *
 *  Created on: Jan 15, 2013
 *      Author: klaus
 */

#include "SymmMatrix.hpp"

/*
 * Member functions
 */
SymmMatrix::SymmMatrix(int n, int init) :
	Matrix(1, n * (n + 1) / 2, 0), vecDim(n * (n + 1) / 2) {
	Matrix::m = n;
	Matrix::n = n;
}

SymmMatrix::~SymmMatrix() {
}

double SymmMatrix::getEntry(int j, int k) const {
	if (j < 0 || j >= getM() || k < 0 || k >= getN())
		throw out_of_range("Indices j or k out of range");

	if (j > k)
		return this->getEntry(k, j);
	/*
	 *     k(k+1)
	 * j + ------
	 *       2
	 */
	return entries[0][j + (k * (k + 1)) / 2];
}

void SymmMatrix::setEntry(int j, int k, double entry) {
	if (j < 0 || j >= getM() || k < 0 || k >= getN())
		throw out_of_range("Indices j or k out of range");

	if (j > k)
		this->setEntry(k, j, entry);
	/*
	 *     k(k+1)
	 * j + ------
	 *       2
	 */
	entries[0][j + (k * (k + 1)) / 2] = entry;
}
