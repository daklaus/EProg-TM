/*
 * Bruch.h
 *
 *  Created on: Dec 10, 2012
 *      Author: klaus
 */

#ifndef BRUCH_HPP_
#define BRUCH_HPP_

#include <iostream>
#include <string>
#include <algorithm>
#include <functional>
#include <cctype>
#include <locale>
#include <cstdlib>
#include <cmath>

using namespace std;

class Bruch {
	long zaehler;
	unsigned long nenner;
public:
	Bruch(int zaehler = 0, unsigned int nenner = 1);
	virtual ~Bruch();
	void setZaehler(long z);
	void setNenner(unsigned long n);
	double getWert() const;
	void setWert(string wert);
	void kuerzen();
	unsigned long getNenner() const;
	long getZaehler() const;
};

#endif /* BRUCH_HPP_ */
