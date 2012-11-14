#define DIM (10)

#include <stdio.h>
#include <stdlib.h>
#include <math.h>


void scanvector(int x[], int n);

long double float2dec(int a[], int m, int e);


int main(int argc, char** argv)
{
	int a[DIM];
	int e=0;
	
	printf("Input the vector of digits a[%d]:\n", DIM);
	scanvector(a, DIM);
	printf("Input the exponent e: ");
	scanf("%d", &e);
	
	printf("The decimal value is: %.10Lf\n", float2dec(a, DIM, e));

	return EXIT_SUCCESS;
}

long double float2dec(int a[], int m, int e)
{
	long double sum=0;
	int i=0;

	for(; i<m; i++) {
		sum += a[i] * powl(2, -(i+1));
	}
	return sum * powl(2, e);
}

void scanvector(int x[], int n)
{
	int i = 0;
	for(i=0; i<n; i++)
	{
		x[i] = 0;
		printf("%d: ", i);
		scanf("%d", &x[i]);
	}
}
