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
	printf("\n");

	endkapital(x, p, n);

	printf("\nInput x_max: ");
	scanf("%lf", &x_max);

	laufzeit(x, p, x_max);

	return EXIT_SUCCESS;
}

void endkapital(double x, double p, int n)
{
	double tmp=x;
	int i=0;

	if(x < 0)
		return;

	printf("Jahr  Kapital\n");
	printf("====  =======\n");

	printf("%4d  %.2f\n", i, tmp);
	for(i=0; i<n; i++)
	{
		tmp = tmp * (1 + p / 100);
		printf("%4d  %.2f\n", i+1, tmp);
	}
}

/*
 * Grundgleichung: x_max = x * (1 + p/100)^n
 * Umgeformt: n = ln(x_max/x)/ln(1 + p/100)
 */
void laufzeit(double x, double p, double x_max)
{
	if(p == 0 || x == 0)
		return;	

	printf("Kapital erreicht in %.2f Jahren!\n", log(x_max/x)/log(1 + p/100));
}
