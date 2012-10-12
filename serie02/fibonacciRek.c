#include <stdio.h>
#include <stdlib.h>
#include <math.h>

int fibonacciRek(int n);

int main(int argc, char** argv)
{
	int n=0;
	
	printf("Insert n: ");
	scanf("%d", &n);

	printf("Fibonacci-Folgenglied x_n = %d\n", fibonacciRek(n));

	return EXIT_SUCCESS;
}

int fibonacciRek(int n)
{
	if(n == 0 || n == 1)
		return n;

	if(n < 0)
		return fibonacciRek(n+2) - fibonacciRek(n+1);
		
	return fibonacciRek(n-1) + fibonacciRek(n-2);
}
