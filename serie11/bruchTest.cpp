/*
 * bruchTest.cpp
 *
 *  Created on: Dec 10, 2012
 *      Author: klaus
 */
#include "Bruch.hpp"

int main(int argc, char** argv) {
	Bruch* b1 = new Bruch(8, 2);
	Bruch* b2 = new Bruch(2, 8);
	string sIn;

	cout << "Bruch b1: " << b1->toString() << " = " << b1->getWert() << endl;

	cout << "kürzen..." << endl;
	b1->kuerzen();
	cout << "Bruch b1: " << b1->toString() << " = " << b1->getWert() << endl;

#if 0
	cout << "String zur Umwandlung: ";
	getline(cin, sIn);
	b1->setWert(sIn);
	cout << b1->toString() << " = " << b1->getWert() << endl;
#endif

	cout << "Bruch b2: " << b2->toString() << " = " << b2->getWert() << endl;

	cout << "b1+b2: " << (*b1 + *b2).toString() << endl;
	cout << "b1-b2: " << (*b1 - *b2).toString() << endl;
	cout << "b1*b2: " << (*b1 * *b2).toString() << endl;
	cout << "b1/b2: " << (*b1 / *b2).toString() << endl;

	delete b1;
	delete b2;

	cout << endl << "Bruch Vergleiche:" << endl;

	b1 = new Bruch(1, 3);
	b2 = new Bruch(1, 2);

	cout << "Wert von " << b1->toString() << ": " << (double) *b1 << endl;
	cout << "Wert von " << b2->toString() << ": " << (double) *b2 << endl;

	if (*b1 < *b2)
		cout << b1->toString() << " < " << b2->toString() << endl;
	if (*b1 <= *b2)
		cout << b1->toString() << " <= " << b2->toString() << endl;
	if (*b1 > *b2)
		cout << b1->toString() << " > " << b2->toString() << endl;
	if (*b1 >= *b2)
		cout << b1->toString() << " >= " << b2->toString() << endl;

	delete b1;
	delete b2;
}
