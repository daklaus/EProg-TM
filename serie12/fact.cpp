/*
 * fact.cpp
 *
 *  Created on: Jan 09, 2012
 *      Author: klaus
 */

#include <iostream>

using namespace std;

long factIt(long n);
long factRek(long n);

int main(int argc, char **argv) {
	cout << "faktIt: " << factIt(5) << endl;
	cout << "faktRek: " << factRek(5) << endl;
}

long factIt(long n) {
	long fact=1;
	int i;

	for (i=2; i<=n; i++) {
		fact *= i;
	}
	return fact;
}

long factRek(long n) {
	if(n == 2)
		return 2;
	if(n <= 1)
		return 1;

	return n*factRek(n-1);
}

