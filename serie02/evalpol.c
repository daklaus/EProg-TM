#include <stdio.h>
#include <stdlib.h>
#include <math.h>

double evalpol(double a0, double a1, double a2, double a3, double x);

int main(int argc, char** argv)
{
	double a0=0, a1=0, a2=0, a3=0, x=0;
	
	printf("Insert a0: ");
	scanf("%lf", &a0);
	
	printf("Insert a1: ");
	scanf("%lf", &a1);
	
	printf("Insert a2: ");
	scanf("%lf", &a2);
	
	printf("Insert a3: ");
	scanf("%lf", &a3);
	
	printf("Insert x: ");
	scanf("%lf", &x);

	printf("p(x) = %.2f", evalpol(a0, a1, a2, a3, x));

	return EXIT_SUCCESS;
}

double evalpol(double a0, double a1, double a2, double a3, double x)
{
	return a0 + a1*x + a2*pow(x,2) + a3*pow(x,3);
}
