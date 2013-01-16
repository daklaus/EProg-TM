/*
 * SpdMatrix.hpp
 *
 *  Created on: Jan 15, 2013
 *      Author: klaus
 */

#ifndef SPDMATRIX_HPP_
#define SPDMATRIX_HPP_

#include "SymmMatrix.hpp"
#include "SquareMatrix.hpp"
#include <cmath>

using namespace std;

class SpdMatrix: public SymmMatrix {
	// stores SPD matrices
public:
	SpdMatrix(int n, int init);
	virtual ~SpdMatrix();

	SquareMatrix chol() const;
};

#endif /* SPDMATRIX_HPP_ */
