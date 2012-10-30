#define DIM (5)

#include <stdio.h>
#include <stdlib.h>
#include <math.h>


void scanvector(double x[], int n);

void printvector(double x[], int n);

void bubblesort(double x[], int n);


int main(int argc, char** argv)
{
	double x[DIM]; /* Vector x element R^n */
	
	printf("Input vector x[%d]:\n", DIM);
	scanvector(x, DIM);
	
	bubblesort(x, DIM);

	printf("Sorted vector x[%d]:\n", DIM);
	printvector(x, DIM);

	return EXIT_SUCCESS;
}

void bubblesort(double x[], int n)
{
	double tmp;
	int m=n, i=0;
	short int swapped=0;

	do {
		swapped = 0;
		for (i=1; i < m; i++) {
			if (x[i-1] > x[i]) {
				tmp = x[i-1];
				x[i-1] = x[i];
				x[i] = tmp;
				swapped = 1;
			}
		}
		m--;
	} while(swapped != 0);
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

void printvector(double x[], int n)
{
	int i = 0;
	printf("(");
	for(i=0; i<n; i++)
	{
		printf("%.2f", x[i]);
		if(i<n-1)
			printf(", ");
	}
	printf(")\n");
}
