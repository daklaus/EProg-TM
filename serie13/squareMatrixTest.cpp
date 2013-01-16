/*
 * personTest.cpp
 *
 *  Created on: Jan 04, 2012
 *      Author: klaus
 */

#include "Matrix.hpp"
#include "SquareMatrix.hpp"

int main(int argc, char **argv) {
	SquareMatrix *pMat;

	/*
	 * 1st test
	 */
	pMat = new SquareMatrix(2, 0);

	pMat->setEntry(0, 0, 4);
	pMat->setEntry(0, 1, 3);
	pMat->setEntry(1, 0, 6);
	pMat->setEntry(1, 1, 3);

	cout << "Original matrix:" << endl;
	pMat->print();

	SquareMatrix lu(pMat->computeLU());
	// LU matrix should be:
	//   4    3
	// 1.5 -1.5

	cout << "LU matrix:" << endl;
	lu.print();

	delete pMat;

	/*
	 * 2nd test
	 */
	cout << endl;

	pMat = new SquareMatrix(3, 0);

	pMat->setEntry(0, 0, 2);
	pMat->setEntry(0, 1, -1);
	pMat->setEntry(0, 2, 3);
	pMat->setEntry(1, 0, 4);
	pMat->setEntry(1, 1, 2);
	pMat->setEntry(1, 2, 1);
	pMat->setEntry(2, 0, -6);
	pMat->setEntry(2, 1, -1);
	pMat->setEntry(2, 2, 2);

	cout << "Original matrix:" << endl;
	pMat->print();

	lu = pMat->computeLU();
	// LU matrix should be:
	//  2  -1   3
	//  2   4  -5
	// -3  -1   6

	cout << "LU matrix:" << endl;
	lu.print();

	delete pMat;
}
