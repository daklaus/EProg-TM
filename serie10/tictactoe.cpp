/*
 * nameTest.cpp
 *
 *  Created on: Dec 11, 2012
 *      Author: klaus
 */
#include "Field.hpp"

#include <iostream>

int main(int argc, char** argv) {
	Field* f = new Field(3);
	size_t j, k;
	WinState state = NOT_ENDED;

	do {
		cout << f->toString();
		cout << "Player " << f->whoIsOnTurn() << " is on turn" << endl;
		cout << "Insert row index (starting from 1): ";
		cin >> j;
		cout << "Insert column index (starting from 1): ";
		cin >> k;
		try {
			state = f->mark(j - 1, k - 1);
		} catch (const out_of_range& e) {
			cout << "Error: " << e.what() << endl;
		}
		cout << endl;
	} while (state == NOT_ENDED);

	cout << f->toString();
	if (state == DRAW) {
		cout << "The game ended tied!" << endl;
	} else {
		cout << "Player " << state << " won!" << endl;
	}

	delete f;
}
