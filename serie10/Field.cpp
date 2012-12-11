/*
 * Field.cpp
 *
 *  Created on: Dec 11, 2012
 *      Author: klaus
 */

#include "Field.hpp"

/*
 * Static function definitions
 */

/*
 * Member functions
 */
Field::Field(size_t n) :
	field(n, vector<char> (n, INIT_CHAR)), n(n), marks(0), winState(NOT_ENDED),
			onTurn(PLR1_ON_TURN) {
}

Field::~Field() {
}

WinState Field::mark(size_t j, size_t k) {
	if (winState != NOT_ENDED)
		return winState;

	if (j < 0 || j >= n || k < 0 || k >= n)
		throw out_of_range("j or k out of range");

	if (field[j][k] != INIT_CHAR)
		return winState;

	switch (onTurn) {
	case PLR1_ON_TURN:
		field[j][k] = PLR1_CHAR;
		onTurn = PLR2_ON_TURN;
		break;
	case PLR2_ON_TURN:
		field[j][k] = PLR2_CHAR;
		onTurn = PLR1_ON_TURN;
		break;
	}

	marks++;

	updateWinStateAt(j, k);

	return winState;
}

void Field::updateWinStateAt(size_t j, size_t k) {
	size_t i, l;
	char setChar;
	bool won;

	if (winState != NOT_ENDED)
		return;

	if (j < 0 || j >= n || k < 0 || k >= n)
		throw out_of_range("row or column index out of range");

	setChar = field[j][k];
	// Check if character was set properly
	if (setChar != PLR1_CHAR && setChar != PLR2_CHAR)
		return;

	// Check row
	won = true;
	for (i = 0; i < n && won; i++) {
		if (field[j][i] != setChar)
			won = false;
	}
	// Check column
	if (!won) {
		won = true;
		for (i = 0; i < n && won; i++) {
			if (field[i][k] != setChar)
				won = false;
		}
	}
	// Check principal diagonal (only if field[j][k] is on it)
	if (!won && j == k) {
		won = true;
		for (i = 0, l = 0; i < n && won; i++, l++) {
			if (field[i][l] != setChar)
				won = false;
		}
	}
	// Check secondary diagonal (only if field[j][k] is on it)
	if (!won && j + k == n - 1) {
		won = true;
		for (i = 0, l = n - 1; i < n && won; i++, l--) {
			if (field[i][l] != setChar)
				won = false;
		}
	}

	// If nobody won
	if (!won) {
		// If all markes are set, it's a draw
		if (marks >= n * n) {
			winState = DRAW;
		}
		return;
	}

	if (setChar == PLR1_CHAR)
		winState = PLR1_WON;
	else if (setChar == PLR2_CHAR)
		winState = PLR2_WON;
}

OnTurn Field::whoIsOnTurn() const {
	return onTurn;
}

WinState Field::whoWon() const {
	return winState;
}

string Field::toString() const {
	ostringstream stream;
	vector<vector<char> >::const_iterator itJ(field.begin());
	vector<vector<char> >::const_iterator itJEnd(field.end());
	vector<char>::const_iterator itK;
	vector<char>::const_iterator itKEnd;
	size_t i;

	// Print upper border
	stream << '+';
	for (i = 0; i < n; i++) {
		stream << "----";
	}
	stream.seekp(-1, stream.cur);
	stream << '+';
	stream << endl;

	// Print entries
	for (; itJ != itJEnd; itJ++) {
		stream << '|';
		for (itK = itJ->begin(), itKEnd = itJ->end(); itK != itKEnd; itK++) {
			stream << ' ' << *itK << " |";
		}
		stream << endl;

		// Print lower border
		stream << '+';
		for (i = 0; i < n; i++) {
			stream << "----";
		}
		stream.seekp(-1, stream.cur);
		stream << '+';
		stream << endl;
	}

	return stream.str();
}

/*
 * Static functions
 */
