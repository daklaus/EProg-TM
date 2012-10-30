#define DIM (5)

#include <stdio.h>
#include <stdlib.h>
#include <math.h>


void scanvector(double x[], int n);

double pnorm(double x[], int n, double p);


int main(int argc, char** argv)
{
	double x[DIM]; /* Vector x element R^n */
	double p=0, pn=0;
	
	printf("Input vector x[%d]:\n", DIM);
	scanvector(x, DIM);
	
	printf("Input p: ");
	scanf("%lf", &p);

	pn = pnorm(x, DIM, p);

	printf("pnorm of vector x[%d]: %.2f\n", DIM, pn);

	return EXIT_SUCCESS;
}

double pnorm(double x[], int n, double p)
{
	double sum=0;
	int i=0;

	if(p < 1) {
		printf("p must lie in [0, inf)\n");
		exit(1);
	}

	for(i=0; i<n; i++) {
		sum += pow(fabs(x[i]), p);
	}

	return pow(sum, 1./p);
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
