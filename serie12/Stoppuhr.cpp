/*
 * Stoppuhr.cpp
 *
 *  Created on: Jan 04, 2013
 *      Author: klaus
 */

#include "Stoppuhr.hpp"

/*
 * Static function definitions
 */


/*
 * Member functions
 */
Stoppuhr::Stoppuhr() : isRunning(false), startTime(-1), endTime(-1) {
}

Stoppuhr::~Stoppuhr() {
}


void Stoppuhr::pushButtonStartStop() {
	if(isRunning) {
		/* Stop */
		endTime = clock();
	} else {
		/* Start */
		startTime = clock();
		endTime = -1;
	}
	isRunning = !isRunning;
}

void Stoppuhr::pushButtonReset() {
	startTime = -1;
	endTime = -1;
	isRunning = false;
}

clock_t Stoppuhr::getTime() const {
	clock_t end;
	
	if(startTime == -1)
		return 0;

	if(isRunning) {
		end = clock();
	} else {
		end = endTime;
	}

	return end - startTime;
}

void Stoppuhr::print() const {
	int hours, minutes;
	double seconds;

	seconds = (double) getTime() / CLOCKS_PER_SEC;
	hours = (int) (seconds / 3600);
	seconds -= hours * 3600;
	minutes = (int) (seconds / 60);
	seconds -= minutes * 60;

	cout << setw(2) << setfill('0') << hours << ':';
	cout << setw(2) << setfill('0') << minutes << ':';
	cout << setw(5) << setfill('0') << fixed << setprecision(2) << seconds << endl;
}
