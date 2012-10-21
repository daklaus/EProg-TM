#include <stdio.h>
#include <stdlib.h>
#include <math.h>


void endkapital(double x, double p, int n);
void laufzeit(double x, double p, double x_max);


int main(int argc, char** argv)
{
	double x=0, p=0, x_max=0;
	int n=0;

	printf("Input x: ");
	scanf("%lf", &x);
	printf("Input p: ");
	scanf("%lf", &p);
	printf("Input n: ");
	scanf("%d", &n);

	endkapital(x, p, n);

	printf("Input x_max: ");
	scanf("%lf", &x_max);

	laufzeit(x, p, x_max);

	return EXIT_SUCCESS;
}

void endkapital(double x, double p, int n)
{
	double tmp=0;
	int i=0;

	printf("Jahr\tKapital\n");
	printf("====\t=======\n");

	for(i=0; i<n; i++)
	{
		
	}
}

double laufzeit(double x, double p, double x_max)
{
}
