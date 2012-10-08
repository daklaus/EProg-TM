#include <stdio.h>
#include <stdlib.h>
#include <math.h>


double folgenglied(int);


int main(int argc, char** argv)
{
	int n=0;
	double a_n=0;
	
	printf("Insert n for progression member a_n: ");
	scanf("%d", &n);

	a_n = folgenglied(n);
	printf("a_n = %f\n", a_n);

	return EXIT_SUCCESS;
}

double folgenglied(int n)
{
	return pow(-1, n) / n;
}
