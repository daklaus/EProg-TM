#include <stdio.h>
#include <stdlib.h>
#include <math.h>


int main(int argc, char** argv)
{
	double x1=0, x2=0, x3=0, r=0, length=0;
	
	printf("Insert the point to check (x1,x2,x3):\nx1: ");
	scanf("%lf", &x1);
	printf("x2: ");
	scanf("%lf", &x2);
	printf("x3: ");
	scanf("%lf", &x3);
	printf("Insert the radius of the sphere: ");
	scanf("%lf", &r);

	length = sqrt(pow(x1,2)+pow(x2,2)+pow(x3,2));

	printf("\n");
	if(length < r)
		printf("The point is in the sphere!\n");
	else if(length == r)
		printf("The point is on the edge of the sphere!\n");
	else
		printf("The point is outside the sphere!\n");

	return EXIT_SUCCESS;
}

