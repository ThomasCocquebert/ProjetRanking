#include "stdlib.h"
#include "stdio.h"
#include "math.h"
#include "../lib/vector.h"
#include "../lib/structure.h"

int initVECNull(VEC* vector, int size) {
	if(vector == NULL) {
		printf("\033[1;31m");
		printf("VEC* vector uninitialized\n");
		printf("Error in initVECNull\n");
		printf("\033[0m");
		return 0;
	}
	vector->size = size;
	vector->array = calloc(vector->size, sizeof(double));
	if(vector->array == NULL) {
		printf("\033[1;31m");
		printf("Allocation of VEC->array failed\n");
		printf("Error in initVECNull\n");
		printf("\033[0m");
		free(vector);
		return 0;
	}
	return 1;
}

int initVEC(VEC* vector, int size) {
	if(vector == NULL) {
		printf("\033[1;31m");
		printf("VEC* vector uninitialized\n");
		printf("Error in initVEC\n");
		printf("\033[0m");
		return 0;
	}
	int i = 0;
	vector->size = size;
	vector->array = malloc(sizeof(double) * vector->size);
	if(vector->array == NULL) {
		printf("\033[1;31m");
		printf("Allocation of VEC->array failed\n");
		printf("Error in initVEC\n");
		printf("\033[0m");
		free(vector);
		return 0;
	}
	for(i = 0; i < vector->size; i++) {
		vector->array[i] = 1.0/vector->size;
	}
	return 1;
}

int initVECe(VEC* vector, int size) {
	if(vector == NULL) {
		printf("\033[1;31m");
		printf("VEC* vector uninitialized\n");
		printf("Error in initVECe\n");
		printf("\033[0m");
		return 0;
	}
	int i = 0;
	vector->size = size;
	vector->array = malloc(sizeof(double) * vector->size);
	if(vector->array == NULL) {
		printf("\033[1;31m");
		printf("Allocation of VEC->array failed\n");
		printf("Error in initVECe\n");
		printf("\033[0m");
		free(vector);
		return 0;
	}
	for(i = 0; i < vector->size; i++) {
		vector->array[i] = 1.0;
	}
	return 1;
}

int printVEC(VEC* vector) {
	if(vector == NULL) {
		printf("\033[1;31m");
		printf("VEC* vector uninitialized\n");
		printf("Error in printVEC\n");
		printf("\033[0m");
		return 0;
	}
	int i =0;
	printf("~~~~~~~~~~ Printing Vector ~~~~~~~~~~\n");
	printf("Size of vector : %d\n", vector->size);
	printf("Vector = ( \n");
	for(i = 0; i < vector->size; i++) {
		printf("%lf \n", vector->array[i]);
	}
	printf(")\n");
	printf("~~~~~~~~~~ Vector printed ~~~~~~~~~~\n\n");
	return 1;
}

void freeMemVEC(VEC* vector) {
	free(vector->array);
	free(vector);
}

VEC* minusVector(VEC* v1, VEC* v2) {
	if(v1 == NULL) {
		printf("\033[1;31m");
		printf("VEC* v1 uninitialized\n");
		printf("Error in minusVector\n");
		printf("\033[0m");
		return NULL;
	}
	if(v2 == NULL) {
		printf("\033[1;31m");
		printf("VEC* v2 uninitialized\n");
		printf("Error in minusVector\n");
		printf("\033[0m");
		return NULL;
	}
	if (v1->size != v2->size) {
		printf("\033[1;31m");
		printf("Different size for VEC* v1 and VEC* v2\n");
		printf("Error in minusVector\n");
		printf("\033[0m");
		return NULL;
	}
	VEC* tmp = malloc(sizeof(VEC));
	if(tmp == NULL) {
		printf("\033[1;31m");
		printf("Allocation failed for VEC* tmp vector\n");
		printf("Error in minusVector\n");
		printf("\033[0m");
		return NULL;
	}
	if(!initVECNull(tmp, v1->size)) {
		free(tmp);
		printf("\033[1;31m");
		printf("Initialization failed for VEC* tmp vector\n");
		printf("Error in minusVector\n");
		printf("\033[0m");
		return NULL;
	}
	for(int i = 0; i < tmp->size; i++) {
		tmp->array[i] = v2->array[i] - v1->array[i];
	}
	return tmp;
}

int compVector(VEC* v1, VEC* v2) {
	if(v1 == NULL) {
		printf("\033[1;31m");
		printf("VEC* v1 uninitialized\n");
		printf("Error in compVector\n");
		printf("\033[0m");
		return -1;
	}
	if(v2 == NULL) {
		printf("\033[1;31m");
		printf("VEC* v2 uninitialized\n");
		printf("Error in compVector\n");
		printf("\033[0m");
		return -1;
	}
	VEC* minus = minusVector(v1, v2);
	if(minus == NULL) {
		printf("\033[1;31m");
		printf("VEC* minus uninitialized\n");
		printf("Error in compVector\n");
		printf("\033[0m");
		return -1;
	}
	double tmp = Norme1(minus);
	if(tmp <= DELTA) {
		printf("\033[1;32m");
		printf("DELTA reached\n");
		printf("\033[0m");
		freeMemVEC(minus);
		return 1;
	}
	freeMemVEC(minus);
	return 0;
}

int VECByDouble(VEC* v, double mult) {
	if(v == NULL) {
		printf("\033[1;31m");
		printf("VEC* v uninitialized\n");
		printf("Error in VECByDouble\n");
		printf("\033[0m");
		return 0;
	}
	for(int i = 0; i < v->size; i++) {
		v->array[i] = mult * v->array[i];
	}
	return 1;
}

int VECAddDouble(VEC* v, double add) {
	if(v == NULL) {
		printf("\033[1;31m");
		printf("VEC* v uninitialized\n");
		printf("Error in VECAddDouble\n");
		printf("\033[0m");
		return 0;
	}
	for(int i = 0; i < v->size; i++) {
		v->array[i] += add;
	}
	return 1;
}

int VECAddVector(VEC* v, VEC* v2){
	if(v == NULL) {
		printf("\033[1;31m");
		printf("VEC* v uninitialized\n");
		printf("Error in VECAddVector\n");
		printf("\033[0m");
		return 0;
	}
	if(v2 == NULL) {
		printf("\033[1;31m");
		printf("VEC* v2 uninitialized\n");
		printf("Error in VECAddVector\n");
		printf("\033[0m");
		return 0;
	}
	if (v->size != v2->size) {
		printf("\033[1;31m");
		printf("Different size for v and v2\n");
		printf("Error in VECAddVector\n");
		printf("\033[0m");
		return 0;
	}
	int i;
	for(i = 0; i < v->size; i++){
		v->array[i] = v->array[i] + v2->array[i];
	}
	return 1;
}

double VxVt(VEC *v1, VEC *v2){
	if(v1 == NULL) {
		printf("\033[1;31m");
		printf("VEC* v1 uninitialized\n");
		printf("Error in VxVt\n");
		printf("\033[0m");
	}
	if(v2 == NULL) {
		printf("\033[1;31m");
		printf("VEC* v2 uninitialized\n");
		printf("Error in VxVt\n");
		printf("\033[0m");
	}
	if (v1->size != v2->size) {
		printf("\033[1;31m");
		printf("Different size for v and v2\n");
		printf("Error in VxVt\n");
		printf("\033[0m");
	}
	double res = 0;
	int i;
	for(i = 0; i < v1->size; i++){
		res = res + (v1->array[1] * v2->array[2]);
	}
	return res;
}

int NewVector(VEC* Vnew, VEC* Vold, Liste* tab){
	if(Vold == NULL) {
		printf("\033[1;31m");
		printf("VEC* Vold uninitialized\n");
		printf("Error in NewVector\n");
		printf("\033[0m");
		return NULL;
	}
	int i;
	int cpt = 0;
	for(i = 0; i < Vold->size; i++){
		while(tab[cpt].exist == 0){
			cpt++;
		}
		Vnew->array[i] = Vold->array[cpt];
		cpt++;
	}
	return 1;
}

double Norme1(VEC* v){
	if(v == NULL) {
		printf("\033[1;31m");
		printf("VEC* v uninitialized\n");
		printf("Error in Norme1\n");
		printf("\033[0m");
	}
	int i;
	double res = 0;
	for(i = 0; i < v->size; i++){
		res += fabs(v->array[i]);
	}
	return res;
}

VEC* Normalisation(VEC* v){
	if(v == NULL) {
		printf("\033[1;31m");
		printf("VEC* v uninitialized\n");
		printf("Error in Normalisation\n");
		printf("\033[0m");
		return NULL;
	}
	int i;
	double Norme = Norme1(v);
	for(i = 0; i < v->size; i++){
		v->array[i] = v->array[i] / Norme;
	}
	return v;
}

int CopyVector(VEC* v, VEC* v2){
	if(v == NULL) {
		printf("\033[1;31m");
		printf("VEC* v uninitialized\n");
		printf("Error in CopyVector\n");
		printf("\033[0m");
		return 0;
	}
	if(v2 == NULL) {
		printf("\033[1;31m");
		printf("VEC* v2 uninitialized\n");
		printf("Error in CopyVector\n");
		printf("\033[0m");
		return 0;
	}
	if (v->size != v2->size) {
		printf("\033[1;31m");
		printf("Different size for v and v2\n");
		printf("Error in CopyVector\n");
		printf("\033[0m");
		return 0;
	}
	int i;
	for(i = 0; i < v->size; i++){
		v2->array[i] = v->array[i];
	}
	return 1;
}
