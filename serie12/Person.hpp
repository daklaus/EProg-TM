/*
 * Person.hpp
 *
 *  Created on: Jan 04, 2013
 *      Author: klaus
 */

#ifndef PERSON_HPP_
#define PERSON_HPP_

#include <iostream>

using namespace std;

class Person {
protected:
	string name;
	string adresse;
public:
	Person();
	Person(string name, string adresse);
	virtual ~Person();

	void setName(string name);
	void setAdresse(string adresse);
	string getName() const;
	string getAdresse() const;

	virtual void print() const;
};

#endif /* PERSON_HPP_ */
