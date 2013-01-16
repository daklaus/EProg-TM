/*
 * binarySearch.cpp
 *
 *  Created on: Jan 16, 2012
 *      Author: klaus
 */

#include <iostream>
#include <cmath>
#include <vector>

using namespace std;

int binarySearch(vector<int> A, int key);

int main(int argc, char **argv) {
	vector<int> vec;
	int i;

	for (i = 0; i < 100; ++i) {
		vec.push_back(2 * i);
	}

	cout << "binarySearch(10): " << binarySearch(vec, 10) << endl;
	cout << "binarySearch(9): " << binarySearch(vec, 9) << endl;
}

int binarySearch(vector<int> A, int key) {
	int imin(0), imax(A.size()), imid;

	// Continue searching while [imin,imax] is not empty
	while (imax >= imin) {
		// Calculate the midpoint for roughly equal partition
		imid = floor((imin + imax) / 2.);

		// Determine which subarray to search
		if (A[imid] < key) {
			// Change min index to search upper subarray
			imin = imid + 1;
		} else if (A[imid] > key) {
			// Change max index to search lower subarray
			imax = imid - 1;
		} else {
			// Key found at index imid
			return imid;
		}
	}
	// Key not found
	return -1;
}
