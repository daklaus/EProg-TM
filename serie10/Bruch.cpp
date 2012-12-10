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
	istringstream trimmer(wert);
	int exp;
	double value = 0;
	double dblPart;
	double intPart = 0;

	trimmer >> value;

	dblPart = modf(value, &intPart);
	exp = 0;
	while (dblPart != 0) {
		dblPart = modf(dblPart * 10, &intPart);
		exp++;
	}

	nenner = pow((long) 10, exp);
	zaehler = value * nenner;
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
