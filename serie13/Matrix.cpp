/*
 * Matrix.cpp
 *
 *  Created on: Jan 6, 2013
 *      Author: klaus
 */

#include "Matrix.hpp"

/*
 * Member functions
 */
Matrix::Matrix(int m, int n, int init) :
	m(m), n(n), entries(vector<vector<double> > (m, vector<double> (n, init))) {
}

Matrix::~Matrix() {
}

int Matrix::getM() const {
	return m;
}

int Matrix::getN() const {
	return n;
}

double Matrix::getEntry(int j, int k) const {
	if (j < 0 || j >= getM() || k < 0 || k >= getN())
		throw out_of_range("Indices j or k out of range");

	return entries[j][k];
}

void Matrix::setEntry(int j, int k, double entry) {
	if (j < 0 || j >= getM() || k < 0 || k >= getN())
		throw out_of_range("Indices j or k out of range");

	entries[j][k] = entry;
}

void Matrix::print() const {
	int m(getM()), n(getN());

	for (int j = 0; j < m; j++) {
		for (int k = 0; k < n; k++) {
			cout << setw(6) << setprecision(2) << getEntry(j, k) << " ";
		}
		cout << endl;
	}
}
