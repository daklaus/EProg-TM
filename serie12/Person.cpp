/*
 * Person.cpp
 *
 *  Created on: Jan 04, 2013
 *      Author: klaus
 */

#include "Person.hpp"

/*
 * Static function definitions
 */


/*
 * Member functions
 */
Person::Person() : name(), adresse() {
}

Person::Person(string name, string adresse) {
	setName(name);
	setAdresse(adresse);
}

Person::~Person() {
}

void Person::setName(string name) {
	this->name = name;
}

void Person::setAdresse(string adresse) {
	this->adresse = adresse;
}


string Person::getName() const {
	return name;
}

string Person::getAdresse() const {
	return adresse;
}

void Person::print() const {
	cout << "Name: " << name << "; Adresse: " << adresse << endl;
}
