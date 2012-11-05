#include <stdio.h>
#include <stdlib.h>
#include <math.h>


double powN(double x, int n);


int main(int argc, char** argv)
{
	double x=0;
	int n=0;
	
	printf("Input x: ");
	scanf("%lf", &x);
	
	printf("Input n: ");
	scanf("%d", &n);

	printf("x^n is %.2f\n", powN(x, n));

	return EXIT_SUCCESS;
}

double powN(double x, int n)
{
	if(n == 0)
		return 1;
	if(n < 0)
		return powN(1./x, -n);
	if(x == 0) {
		if(n < 0)
			return 0./0.;
		return 0;
	}

	return pow(x, n);
}
