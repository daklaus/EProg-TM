/*
 * realVectorTest.cpp
 *
 *  Created on: Dec 16, 2012
 *      Author: klaus
 */

#include "RealVector.hpp"
#include <iostream>

int main(int argc, char **argv) {
	RealVector *pV1 = new RealVector(10);
	RealVector *pV2 = new RealVector(5);

	int i, n;

	cout << "v1:" << endl;
	cout << (const char *) *pV1;

	for (i = 0, n = pV1->getN(); i < n; ++i) {
		(*pV1)[i] = i + 1;
	}

	cout << (const char *) *pV1;

	pV1->resize(15);

	cout << (const char *) *pV1;

	pV1->resize(5);

	cout << (const char *) *pV1;

	for (i = 0, n = pV2->getN(); i < n; ++i) {
		(*pV2)[i] = i + 2;
	}

	cout << "v2:" << endl;
	cout << (const char *) *pV2;

	cout << endl << "v1 + v2:" << endl << (const char *) (*pV1 + *pV2);
	cout << endl << "v1 - v2:" << endl << (const char *) (*pV1 - *pV2);
	cout << endl << "v1 * v2:" << endl << (const char *) (*pV1 * *pV2);
	cout << endl << "v1 / v2:" << endl << (const char *) (*pV1 / *pV2);

	delete pV1;
	delete pV2;
}
