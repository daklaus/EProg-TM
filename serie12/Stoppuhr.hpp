/*
 * Stoppuhr.hpp
 *
 *  Created on: Jan 04, 2013
 *      Author: klaus
 */

#ifndef STOPPUHR_HPP_
#define STOPPUHR_HPP_

#include <iostream>
#include <ctime>
#include <iomanip>

using namespace std;

class Stoppuhr {
	bool isRunning;
	clock_t startTime;
	clock_t endTime;
public:
	Stoppuhr();
	virtual ~Stoppuhr();

	void pushButtonStartStop();
	void pushButtonReset();
	clock_t getTime() const;

	void print() const;
};

#endif /* STOPPUHR_HPP_ */
