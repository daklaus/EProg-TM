/*
 * nameTest.cpp
 *
 *  Created on: Dec 11, 2012
 *      Author: klaus
 */
#include "Name.hpp"

int main(int argc, char** argv) {
	Name* n = new Name();
	string sIn;

	cout << "Geben Sie einen Namen ein: ";
	getline(cin, sIn);
	n->setName(sIn);
	cout << n->printName() << endl;

	delete n;
}
