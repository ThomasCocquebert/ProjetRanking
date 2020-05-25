#include "stdlib.h"
#include "stdio.h"

struct vector
{
	int size;
	double* array;
}; typedef struct vector VEC;

int initVECNull(VEC* vector, int size) {
	vector->size = size;
	vector->array = calloc(vector->size, sizeof(double));
	if(vector->array == NULL) {
		printf("Allocation of VEC->array failed\n");
		return 0;
	} else {
		return 1;
	}
}

int initVEC(VEC* vector, int size) {
	int i = 0;
	vector->size = size;
	vector->array = malloc(sizeof(double) * vector->size);
	if(vector->array == NULL) {
		printf("Allocation of VEC->array failed\n");
		return 0;
	}
	for(i = 0; i < vector->size; i++) {
		vector->array[i] = 1.0/vector->size;
	}
	return 1;
}

void printVEC(VEC* vector) {
	int i =0;
	printf("~~~~~~~~~~ Printing Vector ~~~~~~~~~~\n");
	printf("Size of vector : %d\n", vector->size);
	printf("Vector = ( \n");
	for(i = 0; i < vector->size; i++) {
		printf("%lf \n", vector->array[i]);
	}
	printf(")\n");
	printf("~~~~~~~~~~ Vector printed ~~~~~~~~~~\n\n");
}

void freeMemVEC(VEC* vector) {
	free(vector->array);
	free(vector);
}



int main(int argc, char** argv) {
	VEC* pi = malloc(sizeof(VEC));

	if(pi == NULL) {
		printf("Allocation failed for the vector\n");
		exit(1);
	}

	if(!initVECNull(pi, 10)) {
		exit(1);
	}

	printVEC(pi);
	freeMemVEC(pi);

	VEC* pi2 = malloc(sizeof(VEC));

	if(pi2 == NULL) {
		printf("Allocation failed for the vector\n");
		exit(1);
	}

	if(!initVEC(pi2, 10)) {
		exit(1);
	}

	printVEC(pi2);
	freeMemVEC(pi2);
	exit(0);
}