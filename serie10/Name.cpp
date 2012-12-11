/*
 * Name.cpp
 *
 *  Created on: Dec 11, 2012
 *      Author: klaus
 */

#include "Name.hpp"

/*
 * Static function definitions
 */
static inline std::string &ltrim(std::string &s);
static inline std::string &rtrim(std::string &s);
static inline std::string &trim(std::string &s);

/*
 * Member functions
 */
Name::Name() {
}

Name::~Name() {
}

void Name::setName(string name) {
	size_t lastSpaceIdx;

	trim(name);
	lastSpaceIdx = name.rfind(' ');

	this->nachname = name.substr(lastSpaceIdx + 1);
	this->vorname = trim(name.erase(lastSpaceIdx));
}

string Name::printName() {
	ostringstream stream;
	size_t prevPos = -1;
	size_t pos;

	pos = this->vorname.find(' ', prevPos + 1);
	stream << this->vorname.substr(prevPos + 1, pos - 1 - prevPos) << ' ';
	prevPos = pos;

	while (pos <= this->vorname.size() - 1) {
		pos = this->vorname.find(' ', prevPos + 1);
		stream << this->vorname.at(prevPos + 1) << ". ";
		prevPos = pos;
	}

	stream << this->nachname;
	return stream.str();
}

/*
 * Static functions
 */
// trim from start
static inline std::string &ltrim(std::string &s) {
	s.erase(
			s.begin(),
			std::find_if(s.begin(), s.end(),
					std::not1(std::ptr_fun<int, int>(std::isspace))));
	return s;
}

// trim from end
static inline std::string &rtrim(std::string &s) {
	s.erase(
			std::find_if(s.rbegin(), s.rend(),
					std::not1(std::ptr_fun<int, int>(std::isspace))).base(),
			s.end());
	return s;
}

// trim from both ends
static inline std::string &trim(std::string &s) {
	return ltrim(rtrim(s));
}
