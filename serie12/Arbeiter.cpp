/*
 * Arbeiter.cpp
 *
 *  Created on: Jan 04, 2013
 *      Author: klaus
 */

#include "Arbeiter.hpp"

/*
 * Static function definitions
 */


/*
 * Member functions
 */
Arbeiter::Arbeiter() : Person(), gehalt(), arbeit() {
}

Arbeiter::Arbeiter(string name, string adresse, double gehalt, string arbeit) : Person(name, adresse) {
	setGehalt(gehalt);
	setArbeit(arbeit);
}

Arbeiter::~Arbeiter() {
}

void Arbeiter::setGehalt(double gehalt) {
	this->gehalt = gehalt;
}

void Arbeiter::setArbeit(string arbeit) {
	this->arbeit = arbeit;
}


double Arbeiter::getGehalt() const {
	return gehalt;
}

string Arbeiter::getArbeit() const {
	return arbeit;
}

void Arbeiter::print() const {
	Person::print();
	cout << "Gehalt: " << gehalt << "; Arbeit: " << arbeit << endl;
}
