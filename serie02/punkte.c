#include <stdio.h>
#include <stdlib.h>
#include <math.h>

int punkte(double x, double y, double u, double v, double a, double b);

int main(int argc, char** argv)
{
	double x=0,y=0,u=0,v=0,a=0,b=0;
	
	printf("Insert x: ");
	scanf("%lf", &x);

	printf("Insert y: ");
	scanf("%lf", &y);

	printf("Insert u: ");
	scanf("%lf", &u);

	printf("Insert v: ");
	scanf("%lf", &v);

	printf("Insert a: ");
	scanf("%lf", &a);

	printf("Insert b: ");
	scanf("%lf", &b);

	printf("Die Punkte (x,y), (u,v) und (a,b) sind ");
	if(punkte(x,y,u,v,a,b) == 0)
		printf("nicht ");
	printf("auf einer Geraden!\n");

	return EXIT_SUCCESS;
}

/*
 * Berechne und vergleiche die Steigungen der zwei Geraden
 */
int punkte(double x, double y, double u, double v, double a, double b)
{
	double k1=0, k2=0;

	k1 = (x - u) / (y - v);
	k2 = (u - a) / (v - b);
	
	if(k1 == k2)
		return 1;
	
	return 0;
}
