#include <stdio.h>
#include <stdlib.h>


int main(int argc, char** argv)
{
	double sum=0;
	double tmp;
	int i;

	for(i=1; i<argc; i++) {
		if(sscanf(argv[i], "%lf", &tmp) != 1) {
			fprintf(stderr, "Error parsing argument %d", i);
			return EXIT_FAILURE;
		}
		sum += tmp;
	}

	printf("Mean is: %.2f\n", sum/(argc-1));

	return EXIT_SUCCESS;
}
