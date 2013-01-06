/*
 * SquareMatrix.hpp
 *
 *  Created on: Jan 6, 2013
 *      Author: klaus
 */

#ifndef SQUAREMATRIX_HPP_
#define SQUAREMATRIX_HPP_

#include <vector>
#include "Matrix.hpp"

using namespace std;

class SquareMatrix: public Matrix {
	// stores square matrices
public:
	SquareMatrix(int n, int init);
	virtual ~SquareMatrix();

	SquareMatrix computeLU() const;
	double computeDet() const;
};

#endif /* SQUAREMATRIX_HPP_ */
