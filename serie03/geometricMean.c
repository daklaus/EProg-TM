#define DIM (3)

#include <stdio.h>
#include <stdlib.h>
#include <math.h>


void scanvector(double x[], int n);

double geometricMean(double x[], int n);


int main(int argc, char** argv)
{
	double x[DIM], x_geom = 0;
	
	printf("Insert vector x[%d]:\n", DIM);
	scanvector(x, DIM);
	x_geom = geometricMean(x, DIM);
	printf("The geometric Mean is: %.2f\n", x_geom);

	return EXIT_SUCCESS;
}

double geometricMean(double x[], int n)
{
	int i = 0;
	double prod = 1;
	for(i=0; i<n; i++)
		prod = prod * x[i];
	
	return pow(prod, 1./n);
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
