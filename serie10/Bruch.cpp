/*
 * Bruch.cpp
 *
 *  Created on: Dec 10, 2012
 *      Author: klaus
 */

#include "Bruch.hpp"

/*
 * Static function definitions
 */
static unsigned long ggT(unsigned long a, unsigned long b);
static inline std::string &ltrim(std::string &s);
static inline std::string &rtrim(std::string &s);
static inline std::string &trim(std::string &s);
static inline int isDigitOrDot(int c);

/*
 * Member functions
 */
Bruch::Bruch(int z, unsigned int n) {
	setZaehler(z);
	setNenner(n);
}

Bruch::~Bruch() {
}

void Bruch::setZaehler(long z) {
	zaehler = z;
}

void Bruch::setNenner(unsigned long n) {
	if (n <= 0)
		throw;
	nenner = n;
}

double Bruch::getWert() const {
	return (double) zaehler / (double) nenner;
}

void Bruch::setWert(string wert) {
	char** endPtr = NULL;
	unsigned long exp = 0;
	size_t dotIdx = 0;

	/*
	 * Prepare the string
	 */
	wert = trim(wert);
	// Erase everthing after the first floating point number
	wert.erase(
			find_if(wert.begin(), wert.end(),
					not1(ptr_fun<int, int> (isDigitOrDot))), wert.end());

	dotIdx = wert.find('.');

	if (wert.empty()) {
		this->zaehler = 0;
		this->nenner = 1;
		return;
	}

	// If a dot was found
	if (dotIdx != string::npos) {
		exp = wert.size() - 1 - dotIdx;
		wert.erase(dotIdx, 1);
	} else {
		exp = 0;
	}

	this->nenner = pow((unsigned long) 10, exp);
	this->zaehler = strtoul(wert.c_str(), endPtr, 10);
}

unsigned long Bruch::getNenner() const {
	return nenner;
}

long Bruch::getZaehler() const {
	return zaehler;
}

void Bruch::kuerzen() {
	const unsigned long tmp = ggT(labs(zaehler), nenner);
	zaehler /= tmp;
	nenner /= tmp;
}

/*
 * Static functions
 */
static unsigned long ggT(unsigned long a, unsigned long b) {
	unsigned long tmp;

	while (b != 0) {
		tmp = a % b;
		a = b;
		b = tmp;
	}

	return a;
}

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

static inline int isDigitOrDot(int c) {
	return isdigit(c) || c == (int) '.';
}
