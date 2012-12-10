/*
 * bruchTest.cpp
 *
 *  Created on: Dec 10, 2012
 *      Author: klaus
 */
#include "Bruch.hpp"

int main(int argc, char** argv) {
	Bruch* b = new Bruch();
	string sIn;

	b->setNenner(2);
	b->setZaehler(3);
	cout << "2/3 = " << b->getWert() << endl;

	getline(cin , sIn);

	b->setWert(sIn);
	cout << "Neuer wert: " << b->getWert() << endl;

	delete b;
}
