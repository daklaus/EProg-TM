#include <stdio.h>
#include <stdlib.h>
#include <math.h>


void swap(double* a, double* b);


int main(int argc, char** argv)
{
	double a=0, b=0;
	
	printf("Input a: ");
	scanf("%lf", &a);
	printf("Input b: ");
	scanf("%lf", &b);
	
	swap(&a, &b);

	printf("Now a is %.2f and b is %.2f. Swapped! :O\n", a, b);

	return EXIT_SUCCESS;
}

void swap(double* a, double* b)
{
	double tmp;
	tmp = *a;
	*a = *b;
	*b = tmp;
}
