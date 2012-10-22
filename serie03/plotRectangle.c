#include <stdio.h>
#include <stdlib.h>
#include <math.h>


void plotRectangle(int a, int b);


int main(int argc, char** argv)
{
	int a=0, b=0;

	printf("Input a: ");
	scanf("%d", &a);
	printf("Input b: ");
	scanf("%d", &b);
	printf("\n");

	plotRectangle(a, b);

	return EXIT_SUCCESS;
}

void plotRectangle(int a, int b)
{
	int i=0, j=0;

	for(i=0; i<a; i++)
	{
		for(j=0; j<b; j++)
		{
			printf("X");
		}
		printf("\n");
	}
}
