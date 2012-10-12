#include <stdio.h>
#include <stdlib.h>
#include <math.h>

double myabs(double x);

int main(int argc, char** argv)
{
	double x=0;
	
	printf("Insert x: ");
	scanf("%lf", &x);

	printf("|x| = %.2f\n", myabs(x));

	return EXIT_SUCCESS;
}

double myabs(double x)
{
	return fabs(x);
}
