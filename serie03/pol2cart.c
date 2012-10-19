#include <stdio.h>
#include <stdlib.h>
#include <math.h>


void pol2cart(double r, double phi, double z[]);


int main(int argc, char** argv)
{
	double r=0, phi=0, z[2];
	
	printf("Input r: ");
	scanf("%lf", &r);
	printf("Input phi: ");
	scanf("%lf", &phi);

	pol2cart(r, phi, z);

	printf("Point z = (a,b) is: (%.2f, %.2f)\n", z[0], z[1]);

	return EXIT_SUCCESS;
}

void pol2cart(double r, double phi, double z[])
{
	z[0] = r*cos(phi);
	z[1] = r*sin(phi);
}
