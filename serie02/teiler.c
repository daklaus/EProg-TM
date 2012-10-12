#include <stdio.h>
#include <stdlib.h>
#include <math.h>

void teiler(int x);

int main(int argc, char** argv)
{
	int x=0;
	
	printf("Insert x: ");
	scanf("%d", &x);

	teiler(x);

	return EXIT_SUCCESS;
}

void teiler(int x)
{
	if(x / 2 == x / 2.)
		printf("x ist durch 2 teilbar\n");
	if(x / 3 == x / 3.)
		printf("x ist durch 3 teilbar\n");
	if(x / 6 == x / 6.)
		printf("x ist durch 6 teilbar\n");
}
