#define DIM (5)

#include <stdio.h>
#include <stdlib.h>
#include <math.h>


void scanvector(double x[], int n);

void minmax(double x[], int n, double* min, double* max, int* minIdx, int* maxIdx);


int main(int argc, char** argv)
{
	double x[DIM];
	double max=0, min=0;
	int minIdx=0, maxIdx=0;

	printf("Input the vector of numbers x[%d]:\n", DIM);
	scanvector(x,DIM);

	minmax(x, DIM, &min, &max, &minIdx, &maxIdx);

	printf("min(x) = %.2f at position %d\n", min, minIdx);
	printf("max(x) = %.2f at position %d\n", max, maxIdx);

	return EXIT_SUCCESS;
}

void minmax(double x[], int n, double* min, double* max, int* minIdx, int* maxIdx)
{
	int i=0;

	*min = x[0];
	*max = x[0];
	*minIdx = 0;
	*maxIdx = 0;

	for (i=1; i<n; i++) {
		if (x[i] < *min) {
			*min = x[i];
			*minIdx = i;
		} else if (x[i] > *max) {
			*max = x[i];
			*maxIdx = i;
		}
	}
}

void scanvector(double x[], int n)
{
	int i = 0;
	for(i=0; i<n; i++)
	{
		x[i] = 0;
		printf("%d: ", i);
		scanf("%lf", &x[i]);
	}
}
