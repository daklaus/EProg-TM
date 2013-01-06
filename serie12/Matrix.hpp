/*
 * Matrix.hpp
 *
 *  Created on: Jan 6, 2013
 *      Author: klaus
 */

#ifndef MATRIX_HPP_
#define MATRIX_HPP_

#include <iostream>
#include <vector>
#include <stdexcept>
#include <iomanip>

using namespace std;

class Matrix {
protected:
	int m, n; //dimensions
	vector<vector<double> > entries;
public:
	Matrix(int m, int n, int init);
	virtual ~Matrix();

	int getM() const;
	int getN() const;
	double getEntry(int j, int k) const;
	void setEntry(int j, int k, double entry);
	void print() const;
};

#endif /* MATRIX_HPP_ */
