#include <stdio.h>
#include <stdlib.h>
#include <math.h>


int fact(int x);

double sin_(double x, double epsilon);


int main(int argc, char** argv)
{
	double x=0, epsilon=0, s_n=0, s=0, absError=0;
	
	printf("Input x: ");
	scanf("%lf", &x);
	printf("Input epsilon: ");
	scanf("%lf", &epsilon);

	s_n = sin_(x, epsilon);

	if(s_n == -1) {
		perror("Epsilon must be greater than zero!");
		return EXIT_FAILURE;
	}

	s = sin(x);
	absError = fabs(s_n - s);
	
	printf("S_n(x) = %f\n", s_n);
	printf("sin(x) = %f\n", s);
	printf("absolute error = %f\n", absError);
	if(s != 0) {
		printf("relative error = %f\n", absError / fabs(s));
	} else {
		printf("Couldn't calculate the relative error because sin(x)=0\n");
	}

	return EXIT_SUCCESS;
}


double sin_(double x, double epsilon)
{
	double sum=0, lastSum=0;
	int k=0;

	if(epsilon <= 0)
		return -1;
	
	do {
		lastSum = sum;
		sum += pow(-1, k) * pow(x, 2*k+1) / fact(2*k+1);

		k++;
	} while(fabs(sum-lastSum)/fabs(sum) > epsilon && fabs(sum) > epsilon);

	return sum;
}

int fact(int x)
{
	int i=2, fact=1;
	for (; i<=x; i++) {
		fact *= i;
	}
	return fact;
}
