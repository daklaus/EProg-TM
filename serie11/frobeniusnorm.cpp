/*
 * frobenusnorm.cpp
 *
 *  Created on: Dec 17, 2012
 *      Author: klaus
 */
#include "RealVector.hpp"
#include <iostream>
#include <vector>
#include <cmath>

double frobeniusnorm(const vector<vector<double> >& A);
double frobeniusnorm(const RealVector& A);

int main(int argc, char **argv) {
	vector<vector<double> >::const_iterator itJ;
	vector<double>::const_iterator itK;
	int i;

	/*
	 * Matrix
	 */
	vector<vector<double> > matrix(3, vector<double> (3, 2));

	cout << "Martix:" << endl;
	for (itJ = matrix.begin(); itJ != matrix.end(); ++itJ) {
		for (itK = itJ->begin(); itK != itJ->end(); ++itK) {
			cout << *itK << " ";
		}
		cout << endl;
	}
	cout << endl;

	cout << "Frobeniusnorm: " << frobeniusnorm(matrix) << endl;

	/*
	 * Vector
	 */
	RealVector vec(4);
	for (i = 0; i < vec.getN(); ++i) {
		vec[i] = 3;
	}

	cout << "Vector:" << endl;
	cout << (const char *) vec << endl;

	cout << "Frobeniusnorm: " << frobeniusnorm(vec) << endl;
}

double frobeniusnorm(const vector<vector<double> >& A) {
	double sum = 0;
	vector<vector<double> >::const_iterator itJ(A.begin());
	vector<vector<double> >::const_iterator itJEnd(A.end());
	vector<double>::const_iterator itK;
	vector<double>::const_iterator itKEnd;

	for (; itJ != itJEnd; ++itJ) {
		for (itK = itJ->begin(), itKEnd = itJ->end(); itK != itKEnd; ++itK) {
			sum += *itK * *itK;
		}
	}

	return pow(sum, 1. / 2);
}

double frobeniusnorm(const RealVector& A) {
	double sum = 0;
	int i, n;

	for (i = 0, n = A.getN(); i < n; ++i) {
		sum += A[i] * A[i];
	}

	return pow(sum, 1. / 2);
}
