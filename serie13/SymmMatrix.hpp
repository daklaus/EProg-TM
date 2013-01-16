/*
 * SymmMatrix.hpp
 *
 *  Created on: Jan 15, 2013
 *      Author: klaus
 */

#ifndef SYMMMATRIX_HPP_
#define SYMMMATRIX_HPP_

#include "Matrix.hpp"

using namespace std;

class SymmMatrix: public Matrix {
	// stores symmetric square matrices
	int vecDim;
public:
	SymmMatrix(int n, int init);
	virtual ~SymmMatrix();

	double getEntry(int j, int k) const;
	void setEntry(int j, int k, double entry);
};

#endif /* SYMMMATRIX_HPP_ */
