/*
 * RealVector.hpp
 *
 *  Created on: Dec 16, 2012
 *      Author: klaus
 */

#ifndef REALVECTOR_HPP_
#define REALVECTOR_HPP_

#include <stdexcept>
#include <sstream>
#include <cstdlib>
#include <cstring>

using namespace std;

class RealVector {
	double * entries;
	int n;
public:
	RealVector(int n = 0);
	RealVector(const RealVector& from);
	virtual ~RealVector();

	void resize(int nnew);

	RealVector operator +(const RealVector& rhs) const;
	RealVector operator -(const RealVector& rhs) const;
	RealVector operator *(const RealVector& rhs) const;
	RealVector operator /(const RealVector& rhs) const;
	operator const char *() const;

	inline double& operator[](int const& index) const {
		if (index < 0 || index >= n)
			throw out_of_range("Index out of range");

		return entries[index];
	}

	inline int getN() const {
		return n;
	}
};

#endif /* REALVECTOR_HPP_ */
