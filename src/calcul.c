#include "stdlib.h"
#include "stdio.h"
#include "time.h"
#include "../lib/vector.h"
#include "../lib/structure.h"
#include "../lib/lecture.h"
#include "../lib/calcul.h"

VEC* computeF(Liste *tab, int taille) {
	int i = 0;
	VEC* f = malloc(sizeof(VEC));
	if(f == NULL) {
		printf("\033[1;31m");
		printf("Allocation of VEC failed\n");
		printf("\033[0m");
		return NULL;
	}
	if(!initVECNull(f, taille)) {
		free(f);
		return NULL;
	} 
	for (i=0; i<taille; i++) {
		if (tab[i].first == NULL) {
			f->array[i] = 1;
		}
	}
	return f;
}

VEC* computePiG(Liste* tab, VEC* pi, int size) {
	double tmp = 0.0;
	Sommet* copy;
	VEC* res = malloc(sizeof(VEC));
	if(res == NULL) {
		printf("\033[1;31m");
		printf("Allocation of VEC failed\n");
		printf("\033[0m");
		return NULL;
	}
	if(!initVECNull(res, size)) {
		free(res);
		return NULL;
	}
	for(int i = 0; i < size; i++) {
		if(tab[i].first != NULL) {
			copy = tab[i].first;
			while(tab[i].first != NULL) {
				tmp += tab[i].first->proba * pi->array[tab[i].first->numLigne];
				tab[i].first = tab[i].first->suivant;
			}
			res->array[i] = tmp;
			tmp = 0.0;
			tab[i].first = copy;
		}
	}
	return res;
}

VEC* PageRank(Liste* tab, VEC* x, int size) {
	float alpha = 0.85;
	float mult2 = 0.0;
	float mult3 = (1-alpha)/size;
	VEC* e1 = malloc(sizeof(VEC));
	if(e1 == NULL) {
		printf("\033[1;31m");
		printf("Allocation of VEC failed\n");
		printf("\033[0m");
		return NULL;
	}
	if(!initVECe(e1, size)) {
		free(e1);
		return NULL;
	}
	VEC* e2 = malloc(sizeof(VEC));
	if(e2 == NULL) {
		printf("\033[1;31m");
		printf("Allocation of VEC failed\n");
		printf("\033[0m");
		return NULL;
	}
	if(!initVECe(e2, size)) {
		free(e2);
		return NULL;
	}
	VEC* ft = computeF(tab, size);
	VEC* xTmp = malloc(sizeof(VEC));
	if(xTmp == NULL) {
		printf("\033[1;31m");
		printf("Allocation of VEC failed\n");
		printf("\033[0m");
		return NULL;
	}
	if(!initVECNull(xTmp, size)) {
		free(xTmp);
		return NULL;
	}
	CopyVector(x, xTmp);

	//First part of the PageRank equation
	VEC* piG = computePiG(tab, x, size);
	VECByDouble(piG, alpha);

	//Second part of the PageRank equation
	mult2 = VxVt(xTmp, ft);
	mult2 = alpha * mult2;
	VECByDouble(e1, mult2);

	//Third part of the PageRank equation
	VECByDouble(e2, mult3);

	//Addition of all part and stored the result in piG vector
	VECAddVector(e1, e2);
	VECAddVector(piG, e2);

	//Free allocated memory
	freeMemVEC(e1);
	freeMemVEC(e2);
	freeMemVEC(ft);
	freeMemVEC(xTmp);

	//Return the new vector
	return piG;
}

void Convergence(Liste* tab, VEC* x, int taille){
	
	VEC* xPrec = NULL;
	VEC* tmp = NULL;
	float diff = 0.0;
	for(int i = 0; i < 1000; i++) {
		xPrec = x;
		x = PageRank(tab, x, taille);
		if(x == NULL) {
			printf("ERROR AT EXIT OF PAGERANK FUNCTION\n");
			freeMemVEC(xPrec);
			freeMemVEC(x);
			return;
		}
		tmp = minusVector(x, xPrec);
		if(tmp == NULL) {
			printf("ERROR AT EXIT OF MINUSVECTOR FUNCTION\n");
			freeMemVEC(xPrec);
			freeMemVEC(x);
			freeMemVEC(tmp);
			return;
		}
		diff = Norme1(tmp);
		if(diff <= DELTA) {
			printf("Converge at it %d\n", i);
			printVEC(x);
			freeMemVEC(x);
			freeMemVEC(xPrec);
			freeMemVEC(tmp);
			return;
		}
		freeMemVEC(tmp);
		tmp = NULL;
		freeMemVEC(xPrec);
		xPrec = NULL;
	}
	printf("\033[1;31m");
	printf("No convergence\n");
	printf("\033[0m");
	freeMemVEC(x);
}