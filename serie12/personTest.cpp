/*
 * personTest.cpp
 *
 *  Created on: Jan 04, 2012
 *      Author: klaus
 */

#include "Person.hpp"
#include "Student.hpp"
#include "Arbeiter.hpp"

int main(int argc, char **argv) {
	Person *pStud = new Student("Klaus", "1140 Wien", "0926457", "E33534");
	Person *pArb = new Arbeiter("Roland", "1190 Wien", 1800, "Uni.-Ass.");

	pStud->print();
	cout << endl;
	pArb->print();

	delete pStud;
	delete pArb;
}
