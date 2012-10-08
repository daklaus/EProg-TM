#define PPM (.29)

#include <stdio.h>
#include <stdlib.h>
#include <math.h>


int main(int argc, char** argv)
{
	double g=0;
	
	printf("Insert your balance: ");
	scanf("%lf", &g);

	printf("You can talk for %f minutes!\n", g / PPM);

	return EXIT_SUCCESS;
}

