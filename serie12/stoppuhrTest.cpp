/*
 * stoppuhrTest.cpp
 *
 *  Created on: Jan 04, 2012
 *      Author: klaus
 */

#include "Stoppuhr.hpp"
#include <vector>


void minsort(vector<double>& vec);


int main(int argc, char **argv) {
	Stoppuhr *clock = new Stoppuhr();
	vector<double> *vec = new vector<double>(10000);
	int i, j;

	/* Construct worst-case */
	for(i=0, j=vec->size(); j>0; ++i, --j) {
		(*vec)[i] = j;
	}

	cout << "Minsort started" << endl;
	clock->pushButtonStartStop();
	minsort(*vec);
	clock->pushButtonStartStop();
	cout << "Minsort ended in ";
	clock->print();

	delete clock;
}


void minsort(vector<double>& vec) {
	int j, k, argmin;
	double tmp;
	int n = vec.size();

	for (j=0; j<n-1; ++j) {
		argmin = j;
		for (k=j+1; k<n; ++k) {
			if (vec[argmin] > vec[k]) {
				argmin = k;
			}
		}
		if (argmin > j) {
			tmp = vec[argmin];
			vec[argmin] = vec[j];
			vec[j] = tmp;
		}
	}
}
