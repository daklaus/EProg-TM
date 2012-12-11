/*
 * Name.hpp
 *
 *  Created on: Dec 11, 2012
 *      Author: klaus
 */

#ifndef NAME_HPP_
#define NAME_HPP_

#include <sstream>
#include <iostream>
#include <algorithm>
#include <functional>
#include <cctype>
#include <locale>

using namespace std;

class Name {
	string vorname;
	string nachname;
public:
	Name();
	virtual ~Name();
	void setName(string name);
	string printName();
};

#endif /* NAME_HPP_ */
