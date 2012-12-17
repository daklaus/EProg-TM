/*
 * RealVector.cpp
 *
 *  Created on: Dec 16, 2012
 *      Author: klaus
 */

#include "RealVector.hpp"

RealVector::RealVector(int n) {
	if (n < 0)
		throw range_error("Size must not be negative");

	this->n = n;
	entries = new double[n];
}

RealVector::RealVector(const RealVector& from) {
	n = from.n;
	entries = new double[n];
	memcpy(entries, from.entries, n * sizeof(double));
}

RealVector::~RealVector() {
	delete[] entries;
	entries = 0;
}

void RealVector::resize(int nnew) {
	double *newentries;
	int copysize = min(n, nnew);

	if (nnew < 0)
		throw range_error("Size must not be negative");

	newentries = new double[nnew];
	memcpy(newentries, entries, copysize * sizeof(double));
	delete[] entries;

	entries = newentries;
	n = nnew;
}

RealVector RealVector::operator +(const RealVector& rhs) const {
	RealVector ret(*this);
	int i;

	if (rhs.n != n)
		throw length_error("Lengths of vectors are unequal");

	for (i = 0; i < n; i++) {
		ret.entries[i] += rhs.entries[i];
	}

	return ret;
}

RealVector RealVector::operator -(const RealVector& rhs) const {
	RealVector ret(*this);
	int i;

	if (rhs.n != n)
		throw length_error("Lengths of vectors are unequal");

	for (i = 0; i < n; i++) {
		ret.entries[i] -= rhs.entries[i];
	}

	return ret;
}

RealVector RealVector::operator *(const RealVector& rhs) const {
	RealVector ret(*this);
	int i;

	if (rhs.n != n)
		throw length_error("Lengths of vectors are unequal");

	for (i = 0; i < n; i++) {
		ret.entries[i] *= rhs.entries[i];
	}

	return ret;
}

RealVector RealVector::operator /(const RealVector& rhs) const {
	RealVector ret(*this);
	int i;

	if (rhs.n != n)
		throw length_error("Lengths of vectors are unequal");

	for (i = 0; i < n; i++) {
		ret.entries[i] /= rhs.entries[i];
	}

	return ret;
}

RealVector::operator const char *() const {
	ostringstream stream;
	int i;

	stream << '(';
	for (i = 0; i < n; i++) {
		stream << entries[i] << ", ";
	}
	stream.seekp(-2, stream.cur);
	stream << ')';
	stream << endl;

	return stream.str().c_str();
}
