#include <stdio.h>
#include <stdlib.h>
#include "dynamicvectors.h"

double* mallocvector(int n) {
	if(n < 0) n = 0;
	return calloc(n, sizeof(double));
}


double* freevector(double* vector) {
	if(vector != NULL)
		free(vector);
	return NULL;
}

double* reallocvector(double* vector, int n, int nnew) {
	int i = 0;
	if(nnew < 0) nnew = 0;
	if(n < 0) n = 0;
	vector = realloc(vector, nnew*sizeof(double));
	for (i=n; i<nnew; i++)
		vector[i] = 0;
	return vector;
}

double* scanvector(int n) {
	int i = 0;
	double* vector;
	if(n < 0)
		n = 0;
	vector = malloc(n*sizeof(double));
	for (i=0; i<n; i++) {
		printf("vector[%d]: ",i);
		scanf("%lf", &vector[i]);
	}
	return vector;
}

void printvector(double* vector, int n) {
	int i = 0;
	printf("(");
	for(i=0; i<n; i++)
	{
		printf("%.2f", vector[i]);
		if(i<n-1)
			printf(", ");
	}
	printf(")\n");
}

double maxvector(double* vector, int n) {
	double max=0;
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

double minvector(double* vector, int n) {
	double min=0;
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
