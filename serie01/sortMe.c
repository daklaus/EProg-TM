#include <stdio.h>
#include <stdlib.h>

int main(int argc, char** argv)
{
	double a=0, b=0, c=0;
	
	printf("Insert number a: ");
	scanf("%lf", &a);
	printf("Insert number b: ");
	scanf("%lf", &b);
	printf("Insert number c: ");
	scanf("%lf", &c);
	
	if(a <= b)
	{
		if(b <= c)
			printf("Ordered sequence: %f, %f, %f\n", a, b, c);
		else
		{
			if(a <= c)
				printf("Ordered sequence: %f, %f, %f\n", a, c, b);
			else
				printf("Ordered sequence: %f, %f, %f\n", c, a, b);
		}
	}
	else
	{
		if(b >= c)
			printf("Ordered sequence: %f, %f, %f\n", c, b, a);
		else
		{
			if(a <= c)
				printf("Ordered sequence: %f, %f, %f\n", b, a, c);
			else
				printf("Ordered sequence: %f, %f, %f\n", b, c, a);
		}
	}

	return EXIT_SUCCESS;
}
