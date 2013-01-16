/*
 * spdMatrixTest.cpp
 *
 *  Created on: Jan 15, 2012
 *      Author: klaus
 */

#include "SpdMatrix.hpp"

int main(int argc, char **argv) {
	SpdMatrix *pMat;

	/*
	 * 1st test
	 */
	pMat = new SpdMatrix(4, 0);

	pMat->setEntry(0, 0, 9);
	pMat->setEntry(0, 1, 3);
	pMat->setEntry(0, 2, -6);
	pMat->setEntry(0, 3, 12);
	pMat->setEntry(1, 1, 26);
	pMat->setEntry(1, 2, -7);
	pMat->setEntry(1, 3, -11);
	pMat->setEntry(2, 2, 9);
	pMat->setEntry(2, 3, 7);
	pMat->setEntry(3, 3, 65);

	cout << "Original matrix:" << endl;
	pMat->print();

	SquareMatrix l(pMat->chol());
	// L matrix should be:
	//  3   0   0   0
	//  1   5   0   0
	// -2  -1   2   0
	//  4  -3   6   2

	cout << "L matrix:" << endl;
	l.print();

	delete pMat;
}
