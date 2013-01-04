/*
 * Arbeiter.hpp
 *
 *  Created on: Jan 04, 2013
 *      Author: klaus
 */

#ifndef ARBEITER_HPP_
#define ARBEITER_HPP_

#include <iostream>
#include "Person.hpp"

using namespace std;

class Arbeiter : public Person {
private:
	double gehalt;
	string arbeit;
public:
	Arbeiter();
	Arbeiter(string name, string adresse, double gehalt, string arbeit);
	virtual ~Arbeiter();

	void setGehalt(double gehalt);
	void setArbeit(string arbeit);
	double getGehalt() const;
	string getArbeit() const;

	void print() const;
};

#endif /* ARBEITER_HPP_ */
