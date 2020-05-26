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

VEC* minusVector(VEC* v1, VEC* v2) {
	if (v1->size != v2->size) {
		printf("\033[1;31m");
		printf("Different size for v1 and v2\n");
		printf("\033[0m");
		return NULL;
	}
	VEC* tmp = malloc(sizeof(VEC));
	if(tmp == NULL) {
		printf("\033[1;31m");
		printf("Allocation failed for tmp vector\n");
		printf("\033[0m");
		return NULL;
	}
	if(!initVECNull(tmp, v1->size)) {
		free(tmp);
		return NULL;
	}
	for(int i = 0; i < tmp->size; i++) {
		tmp->array[i] = v2->array[i] - v1->array[i];
	}
	return tmp;
}

int compVector(VEC* v1, VEC* v2) {
	VEC* minus = minusVector(v1, v2);
	if(minus == NULL) {
		return -1;
	}
	double tmp = 0.0;
	for(int i = 0; i < minus->size; i++) {
		tmp += minus->array[i]*minus->array[i];
	}
	tmp = sqrt(tmp);
	printf("norm : %lf\n", tmp);
	if(tmp <= DELTA) {
		printf("\033[1;32m");
		printf("DELTA reached\n");
		printf("\033[0m");
		freeMemVEC(minus);
		return 1;
	} else {
		freeMemVEC(minus);
		return 0;
	}
}