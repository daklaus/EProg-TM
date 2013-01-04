/*
 * Student.hpp
 *
 *  Created on: Jan 04, 2013
 *      Author: klaus
 */

#ifndef STUDENT_HPP_
#define STUDENT_HPP_

#include <iostream>
#include "Person.hpp"

using namespace std;

class Student : public Person {
private:
	string matrikelnummer;
	string studium;
public:
	Student();
	Student(string name, string adresse, string matrikelnummer, string studium);
	virtual ~Student();

	void setMatrikelnummer(string matrikelnummer);
	void setStudium(string studium);
	string getMatrikelnummer() const;
	string getStudium() const;

	void print() const;
};

#endif /* STUDENT_HPP_ */
