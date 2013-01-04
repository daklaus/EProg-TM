/*
 * Student.cpp
 *
 *  Created on: Jan 04, 2013
 *      Author: klaus
 */

#include "Student.hpp"

/*
 * Static function definitions
 */


/*
 * Member functions
 */
Student::Student() : Person(), matrikelnummer(), studium() {
}

Student::Student(string name, string adresse, string matrikelnummer, string studium) : Person(name, adresse) {
	setMatrikelnummer(matrikelnummer);
	setStudium(studium);
}

Student::~Student() {
}

void Student::setMatrikelnummer(string matrikelnummer) {
	this->matrikelnummer = matrikelnummer;
}

void Student::setStudium(string studium) {
	this->studium = studium;
}


string Student::getMatrikelnummer() const {
	return matrikelnummer;
}

string Student::getStudium() const {
	return studium;
}

void Student::print() const {
	Person::print();
	cout << "Matrikelnummer: " << matrikelnummer << "; Studium: " << studium << endl;
}
