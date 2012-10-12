#include <stdio.h>
#include <stdlib.h>
#include <math.h>

int main(int argc, char** argv)
{
	int z=0, n=0, ggT=0;
	double zn=0, z2=0, n2=0;
	
	printf("Insert z: ");
	scanf("%d", &z);

	printf("Insert n: ");
	scanf("%d", &n);

	if(n == 0)
	{
		perror("Division durch 0 ungültig!\n");
		return EXIT_FAILURE;
	}

	printf("Insert ggT: ");
	scanf("%d", &ggT);
	printf("\n");

	zn = (double) z / n;
	printf("z/n = %.2f\n", zn);

	z2 = (double) z / ggT;
	n2 = (double) n / ggT;

	if(z2 != (int)z2 || n2 != (int) n2)
	{
		perror("ggT ist kein gültiger Teiler!\n");
		return EXIT_FAILURE;
	}

	printf("Der gekürzte Bruch ist: %.0f/%.0f\n", z2, n2);

	return EXIT_SUCCESS;
}
