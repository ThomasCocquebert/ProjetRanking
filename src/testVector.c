#include "stdlib.h"
#include "stdio.h"
#include "../lib/vector.h"


int main(int argc, char** argv) {
	printf("Allocation of vector null\n");
	VEC* pi = malloc(sizeof(VEC));
	if(pi == NULL) {
		printf("\033[1;31m");
		printf("Allocation failed for the vector\n");
		printf("\033[0m");
		exit(1);
	}
	if(!initVECNull(pi, 10)) {
		exit(1);
	}
	printVEC(pi);

	printf("Allocation of vector\n");
	VEC* pi2 = malloc(sizeof(VEC));
	if(pi2 == NULL) {
		printf("\033[1;31m");
		printf("Allocation failed for the vector\n");
		printf("\033[0m");
		exit(1);
	}
	if(!initVEC(pi2, 10)) {
		exit(1);
	}
	printVEC(pi2);

	switch(compVector(pi, pi2)) {
		case 0:
			printf("pi and pi2 has difference > DELTA\n");
			break;

		case 1:
			printf("pi and pi2 has difference <= DELTA\n");
			break;

		default:
			printf("Exit programm\n");
			freeMemVEC(pi);
			freeMemVEC(pi2);
			exit(1);
	}

	switch(compVector(pi2, pi2)) {
		case 0:
			printf("pi2 and pi2 has difference > DELTA\n");
			break;

		case 1:
			printf("pi2 and pi2 has difference <= DELTA\n");
			break;

		default:
			printf("Exit programm\n");
			freeMemVEC(pi);
			freeMemVEC(pi2);
			exit(1);
	}

	VEC* pi3 = malloc(sizeof(VEC));
	if(pi3 == NULL) {
		printf("\033[1;31m");
		printf("Allocation failed for the vector\n");
		printf("\033[0m");
		exit(1);
	}
	if(!initVEC(pi3, 10)) {
		exit(1);
	}
	printVEC(pi3);

	VECByDouble(pi3, 0.5);
	printVEC(pi3);
	VECAddDouble(pi3, 0.05);
	printVEC(pi3);

	VEC* pi4 = malloc(sizeof(VEC));
	if(pi4 == NULL) {
		printf("\033[1;31m");
		printf("Allocation failed for the vector\n");
		printf("\033[0m");
		exit(1);
	}
	if(!initVECe(pi4, 10)) {
		exit(1);
	}
	printVEC(pi4);

	VEC* pi5 = malloc(sizeof(VEC));
	if(pi5 == NULL) {
		printf("\033[1;31m");
		printf("Allocation failed for the vector\n");
		printf("\033[0m");
		exit(1);
	}
	if(!initVEC(pi5, 10)) {
		exit(1);
	}
	printVEC(pi5);

	printf("V2 * e = %lf\n", VxVt(pi2, pi4));

	freeMemVEC(pi);
	freeMemVEC(pi2);
	freeMemVEC(pi3);
	freeMemVEC(pi4);
	freeMemVEC(pi5);

	exit(0);
}