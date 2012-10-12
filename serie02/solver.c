#include <stdio.h>
#include <stdlib.h>
#include <math.h>

int main(int argc, char** argv)
{
	double a=0, b=0, c=0, D=0;
	
	printf("Insert a: ");
	scanf("%lf", &a);
	
	printf("Insert b: ");
	scanf("%lf", &b);
	
	printf("Insert c: ");
	scanf("%lf", &c);

	if(a == 0)
	{
		if(b == 0)
		{
			printf("Die Gleichung hat keine Lösungen, da a=0 und b=0!\n");
			return EXIT_SUCCESS;
		}
		printf("x = %.2f\n", - c / b);
		return EXIT_SUCCESS;
	}

	D = pow(b,2) - 4*a*c;

	if(D < 0)
	{
		printf("Die Gleichung hat keine reellen Lösungen!\n");
		return EXIT_SUCCESS;
	}

	printf("x1 = %.2f\n", (- b + sqrt(pow(b,2) - 4*a*c)) / (2*a));
	printf("x2 = %.2f\n", (- b - sqrt(pow(b,2) - 4*a*c)) / (2*a));

	return EXIT_SUCCESS;
}
