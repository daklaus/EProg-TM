#include <stdio.h>
#include <stdlib.h>
#include <math.h>

#define M_PI (3.14159265358979323846)

int main(int argc, char** argv)
{
	double r=0, h=0, area=0, volume=0;
	
	printf("Insert radius: ");
	scanf("%lf", &r);
	printf("Insert height: ");
	scanf("%lf", &h);
	
	area = M_PI * r * r;
	printf("Area of the circle: A=%f\n", area);

	if(h == 0)
		return EXIT_SUCCESS;

	volume = area * h / 3;
	printf("Volume of the cone: V=%f\n", volume);

	return EXIT_SUCCESS;
}
