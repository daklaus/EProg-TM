#define DIM (10)

#include <stdio.h>
#include <stdlib.h>
#include <math.h>


void printvector(int x[], int n);

void dec2float(double x, int n, int b[], int* e);


int main(int argc, char** argv)
{
	int b[DIM];
	double x=0;
	int e=0;
	
	printf("Input x: ");
	scanf("%lf", &x);
	
	dec2float(x, DIM, b, &e);

	if(x <= 0) {
		printf("x has to be greater than zero!\n");
		return EXIT_SUCCESS;
	}

	printf("x with base 2: ");
	printvector(b, DIM);
	printf("The exponent e is: %d\n", e);

	return EXIT_SUCCESS;
}

void dec2float(double x, int n, int b[], int* e)
{
	double decimalPart=0;
	int integerPart=0;
	int i=0, bTmp=0;

	if(x <= 0)
		return;

	integerPart = (int) x;
	decimalPart = x - integerPart;

	if(integerPart > 0) {
		*e = floor(log(integerPart)/log(2))+1;
	} else {
		*e = 0;
	}

	/* Calculate integer part */
	for(i=*e-1; i>=0; i--) {
		bTmp = integerPart % 2;
		integerPart = integerPart / 2;

		if(i < n)
			b[i] = bTmp;
	}

	/* Calculate decimal part */
	for(i=*e; i<n; i++) {
		decimalPart = decimalPart * 2;
		b[i] = (int) decimalPart;
		decimalPart = decimalPart - (int) decimalPart;
	}
}

void printvector(int x[], int n)
{
	int i = 0;
	for(i=0; i<n; i++) {
		printf("%d", x[i]);
	}
	printf("\n");
}
