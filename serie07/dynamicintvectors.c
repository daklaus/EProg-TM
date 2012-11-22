#include <stdio.h>
#include <stdlib.h>
#include "dynamicintvectors.h"

int* mallocintvector(int n) {
	if(n < 0) n = 0;
	return calloc(n, sizeof(int));
}


int* freeintvector(int* vector) {
	if(vector != NULL)
		free(vector);
	return NULL;
}

int* reallocintvector(int* vector, int n, int nnew) {
	int i = 0;
	if(nnew < 0) nnew = 0;
	if(n < 0) n = 0;
	vector = realloc(vector, nnew*sizeof(int));
	for (i=n; i<nnew; i++)
		vector[i] = 0;
	return vector;
}

int* scanintvector(int n) {
	int i = 0;
	int* vector;
	if(n < 0)
		n = 0;
	vector = malloc(n*sizeof(int));
	for (i=0; i<n; i++) {
		printf("vector[%d]: ",i);
		scanf("%d", &vector[i]);
	}
	return vector;
}

void printintvector(int* vector, int n) {
	int i = 0;
	printf("(");
	for(i=0; i<n; i++)
	{
		printf("%d", vector[i]);
		if(i<n-1)
			printf(", ");
	}
	printf(")\n");
}

int maxintvector(int* vector, int n) {
	int max=0;
	int i;

	if(n <= 0)
		return 0;

	max = vector[0];
	for(i=0; i<n; i++) {
		if(vector[i] > max)
			max = vector[i];
	}
	return max;
}

int minintvector(int* vector, int n) {
	int min=0;
	int i;

	if(n <= 0)
		return 0;

	min = vector[0];
	for(i=0; i<n; i++) {
		if(vector[i] < min)
			min = vector[i];
	}
	return min;
}
