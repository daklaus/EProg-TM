/*
 * Field.hpp
 *
 *  Created on: Dec 11, 2012
 *      Author: klaus
 */

#ifndef FIELD_HPP_
#define FIELD_HPP_

#define INIT_CHAR (' ')
#define PLR1_CHAR ('X')
#define PLR2_CHAR ('O')

#include <vector>
#include <stdexcept>
#include <sstream>

using namespace std;

enum WinState {
	NOT_ENDED = -1, DRAW = 0, PLR1_WON = 1, PLR2_WON = 2
};
enum OnTurn {
	PLR1_ON_TURN = 1, PLR2_ON_TURN = 2
};

class Field {
	vector<vector<char> > field;
	const size_t n;
	unsigned int marks;
	WinState winState;
	OnTurn onTurn;
private:
	void updateWinStateAt(size_t j, size_t k);
public:
	Field(size_t n = 3);
	virtual ~Field();
	WinState mark(size_t j, size_t k);
	OnTurn whoIsOnTurn() const;
	WinState whoWon() const;
	string toString() const;
};

#endif /* FIELD_HPP_ */
