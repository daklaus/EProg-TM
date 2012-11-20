#include <stdio.h>
#include <stdlib.h>
#include <math.h>


int* scanvector(int n);

void printvector(int x[], int n);

int* unique(int x[], int n);


int main(int argc, char** argv)
{
	int n=0;
	int* array;

	printf("Input the size of the array: ");
	scanf("%d", &n);
	printf("Input the array[%d]: ", n);
	array = scanvector(n);

	array = unique(array, &n);

	printf("Sorted and unique array is:\n");
	printvector(array, n);

	free(array);

	return EXIT_SUCCESS;
}

int* unique(int x[], int* n)
{
	int i=0, curMinIdx=0;
	int newN=1;
	int* y;

	if(*n <= 0)
		return x;

	y = (int*) malloc(sizeof(int));
	y[0] = x[0];
	
	curMinIdx=0;
	for(i=0; i<*n; i++) {
	}

	return NULL;
}

int* scanvector(int n)
{
	int i = 0;

	if(n < 0)
		n = 0;

	int* x = (int*) calloc(n, sizeof(int));

	for(i=0; i<n; i++) {
		x[i] = 0;
		printf("%d: ", i);
		scanf("%d", &x[i]);
	}

	return x;
}

void printvector(int x[], int n)
{
	int i = 0;
	printf("(");
	for(i=0; i<n; i++)
	{
		printf("%d", x[i]);
		if(i<n-1)
			printf(", ");
	}
	printf(")\n");
}
