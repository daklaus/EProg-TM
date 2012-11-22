#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <limits.h>


int* scanvector(int n);

void printvector(int x[], int n);

int* unique(int x[], int* n);


int main(int argc, char** argv)
{
	int n=0;
	int* aIn;
	int* aOut;

	printf("Input the size of the array: ");
	scanf("%d", &n);
	printf("Input the array[%d]:\n", n);
	aIn = scanvector(n);

	aOut = unique(aIn, &n);
	if(aIn != aOut)
		free(aIn);

	printf("Sorted and unique array is:\n");
	printvector(aOut, n);

	free(aOut);

	return EXIT_SUCCESS;
}

int* unique(int x[], int* n)
{
	int i=0, newN=1, lowerBound=0, curMin=0;
	int* y = NULL;
	unsigned char foundMin=0;

	if(*n <= 0)
		return x;

	lowerBound = INT_MIN;
	
	do {
		foundMin = 0;
		curMin = INT_MAX;

		for(i=0; i<*n; i++) {
			if(x[i] <= curMin && x[i] > lowerBound) {
				curMin = x[i];
				foundMin = 1;
			}
		}

		if(foundMin) {
			lowerBound = curMin;
			y = (int*) realloc(y, newN);
			y[newN-1] = curMin;
			newN++;
		}
	} while(foundMin);

	/* Because at the end of the loop y is one too big */
	y = (int*) realloc(y, --newN);

	*n = newN;

	return y;
}

int* scanvector(int n)
{
	int i = 0;
	int* x;

	if(n < 0)
		n = 0;

	x = (int*) calloc(n, sizeof(int));

	for(i=0; i<n; i++) {
		x[i] = 0;
		printf("%d: ", i);
		scanf("%d", &x[i]);
	}

	return x;
}

void printvector(int x[], int n)
{
	int i = 0;
	printf("(");
	for(i=0; i<n; i++)
	{
		printf("%d", x[i]);
		if(i<n-1)
			printf(", ");
	}
	printf(")\n");
}
