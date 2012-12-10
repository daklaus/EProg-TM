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

	b->setNenner(8);
	b->setZaehler(2);
	cout << b->getZaehler() << " / " << b->getNenner() << " = " << b->getWert()
			<< endl;

	cout << "kürzen..." << endl;
	b->kuerzen();
	cout << b->getZaehler() << " / " << b->getNenner() << " = " << b->getWert()
			<< endl;

	cout << "String zur Umwandlung: ";
	getline(cin, sIn);
	b->setWert(sIn);
	cout << b->getZaehler() << " / " << b->getNenner() << " = " << b->getWert()
			<< endl;

	delete b;
}
