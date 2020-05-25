#include "stdlib.h"
#include "stdio.h"
#include "../lib/vector.h"
#include "math.h"

int initVECNull(VEC* vector, int size) {
	vector->size = size;
	vector->array = calloc(vector->size, sizeof(double));
	if(vector->array == NULL) {
		printf("\033[1;31m");
		printf("Allocation of VEC->array failed\n");
		printf("\033[0m");
		free(vector);
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
		printf("\033[1;31m");
		printf("Allocation of VEC->array failed\n");
		printf("\033[0m");
		free(vector);
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

int compVector(VEC* v1, VEC* v2) {
	if(v1->size != v2->size) {
		printf("\033[1;31m");
		printf("Different size for v1 and v2\n");
		printf("\033[0m");
		return -1;
	}

	for(int i = 0; i < v1->size; i++) {
		//printf("abs : %lf DELTA : %lf\n", abs((v1->array[i]-v2->array[i])), DELTA);
		if(fabs((v1->array[i]-v2->array[i])) > DELTA) {
			return 0;
		}
	}

	return 1;
}