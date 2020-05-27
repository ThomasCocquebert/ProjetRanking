#include "stdlib.h"
#include "stdio.h"
#include "time.h"
#include "../lib/structure.h"
#include "../lib/vector.h"
#include "../lib/lecture.h"
#include "../lib/calcul.h"

VEC* computeF(Liste *tab, int taille) {
	int i = 0;
	int cpt = 0;
	VEC* f = malloc(sizeof(VEC));
	if(f == NULL) {
		printf("\033[1;31m");
		printf("Allocation of VEC* f failed\n");
		printf("Error in computeF\n");
		printf("\033[0m");
		return NULL;
	}
	if(!initVECNull(f, taille)) {
		free(f);
		printf("\033[1;31m");
		printf("Initialization of VEC* f failed\n");
		printf("Error in computeF\n");
		printf("\033[0m");
		return NULL;
	} 
	for (i = 0; i < taille; i++) {
		while(tab[cpt].exist == 0){
			cpt++;
		}
		if (tab[cpt].first == NULL) {
			f->array[i] = 1;
		}
		cpt++;
		}
	return f;
}

VEC* computePiG(Liste* tab, VEC* pi, int size) {
	int cptTab = 0;
	double tmp = 0.0;
	Sommet* copy;
	VEC* res = malloc(sizeof(VEC));
	if(res == NULL) {
		printf("\033[1;31m");
		printf("Allocation of VEC* res failed\n");
		printf("Error in computePiG\n");
		printf("\033[0m");
		return NULL;
	}
	if(!initVECNull(res, size)) {
		free(res);
		printf("\033[1;31m");
		printf("Allocation of VEC* res failed\n");
		printf("Error in computePiG\n");
		printf("\033[0m");
		return NULL;
	}

	for(int i = 0; i < size; i++) {
		while(tab[cptTab].exist == 0) {
			cptTab++;
		}
		if(tab[cptTab].first != NULL) {
			copy = tab[cptTab].first;
			while(tab[cptTab].first != NULL) {
				tmp += tab[cptTab].first->proba * pi->array[tab[cptTab].first->numLigne];
				tab[cptTab].first = tab[cptTab].first->suivant;
			}
			res->array[i] = tmp;
			tmp = 0.0;
			tab[cptTab].first = copy;
		}
		cptTab++;
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
		printf("Allocation of VEC* e1 failed\n");
		printf("Error in PageRank\n");
		printf("\033[0m");
		return NULL;
	}
	if(!initVECe(e1, size)) {
		free(e1);
		printf("\033[1;31m");
		printf("Initialization of VEC* e1 failed\n");
		printf("Error in PageRank\n");
		printf("\033[0m");
		return NULL;
	}
	VEC* e2 = malloc(sizeof(VEC));
	if(e2 == NULL) {
		printf("\033[1;31m");
		printf("Allocation of VEC* e2 failed\n");
		printf("Error in PageRank\n");
		printf("\033[0m");
		return NULL;
	}
	if(!initVECe(e2, size)) {
		freeMemVEC(e1);
		free(e2);
		printf("\033[1;31m");
		printf("Initialization of VEC* e2 failed\n");
		printf("Error in PageRank\n");
		printf("\033[0m");
		return NULL;
	}
	VEC* ft = computeF(tab, size);
	if(ft == NULL) {
		freeMemVEC(e1);
		freeMemVEC(e2);
		printf("\033[1;31m");
		printf("Initialization of VEC* ft failed\n");
		printf("Error in PageRank\n");
		printf("\033[0m");
	}
	VEC* xTmp = malloc(sizeof(VEC));
	if(xTmp == NULL) {
		printf("\033[1;31m");
		printf("Allocation of VEC* xTmp failed\n");
		printf("Error in PageRank\n");
		printf("\033[0m");
		return NULL;
	}
	if(!initVECNull(xTmp, size)) {
		freeMemVEC(e1);
		freeMemVEC(e2);
		freeMemVEC(ft);
		free(xTmp);
		printf("\033[1;31m");
		printf("Initialization of VEC* xTmp failed\n");
		printf("Error in PageRank\n");
		printf("\033[0m");
		return NULL;
	}
	if(!CopyVector(x, xTmp)) {
		freeMemVEC(e1);
		freeMemVEC(e2);
		freeMemVEC(ft);
		freeMemVEC(xTmp);
		printf("\033[1;31m");
		printf("Copy of x in xTmp failed\n");
		printf("Error in PageRank\n");
		printf("\033[0m");
		return NULL;
	}

	//First part of the PageRank equation
	VEC* piG = computePiG(tab, x, size);
	if(piG == NULL) {
		freeMemVEC(e1);
		freeMemVEC(e2);
		freeMemVEC(ft);
		freeMemVEC(xTmp);
		printf("\033[1;31m");
		printf("Initialization of VEC* piG failed\n");
		printf("Error in PageRank\n");
		printf("\033[0m");
		return NULL;
	}
	VECByDouble(piG, alpha);

	//Second part of the PageRank equation
	mult2 = VxVt(xTmp, ft);
	mult2 = alpha * mult2;
	if(!VECByDouble(e1, mult2)) {
		freeMemVEC(e1);
		freeMemVEC(e2);
		freeMemVEC(ft);
		freeMemVEC(xTmp);
		freeMemVEC(piG);
		printf("\033[1;31m");
		printf("VECByDouble(e1,mult2) failed\n");
		printf("Error in PageRank\n");
		printf("\033[0m");
		return NULL;
	}

	//Third part of the PageRank equation
	if(!VECByDouble(e2, mult3)) {
		freeMemVEC(e1);
		freeMemVEC(e2);
		freeMemVEC(ft);
		freeMemVEC(xTmp);
		freeMemVEC(piG);
		printf("\033[1;31m");
		printf("VECByDouble(e2,mult3) failed\n");
		printf("Error in PageRank\n");
		printf("\033[0m");
		return NULL;
	}

	//Addition of all part and stored the result in piG vector
	if(!VECAddVector(e1, e2)) {
		freeMemVEC(e1);
		freeMemVEC(e2);
		freeMemVEC(ft);
		freeMemVEC(xTmp);
		freeMemVEC(piG);
		printf("\033[1;31m");
		printf("VECAddVector(e1,e2) failed\n");
		printf("Error in PageRank\n");
		printf("\033[0m");
		return NULL;
	}
	if(!VECAddVector(piG, e2)) {
		freeMemVEC(e1);
		freeMemVEC(e2);
		freeMemVEC(ft);
		freeMemVEC(xTmp);
		freeMemVEC(piG);
		printf("\033[1;31m");
		printf("VECAddVector(piG,e2) failed\n");
		printf("Error in PageRank\n");
		printf("\033[0m");
		return NULL;
	}

	//Free allocated memory
	freeMemVEC(e1);
	freeMemVEC(e2);
	freeMemVEC(ft);
	freeMemVEC(xTmp);

	//Return the new vector
	return piG;
}

VEC* Convergence(Liste* tab, VEC* x, int taille){
	VEC* xPrec = NULL;
	for(int i = 0; i < 1000; i++) {
		printf("Compute iteration %d\n", i);
		xPrec = x;
		x = PageRank(tab, x, taille);
		if(x == NULL) {
			printf("\033[1;31m");
			printf("x uninitialized with PageRank\n");
			printf("Error in Convergence\n");
			printf("\033[0m");
			freeMemVEC(xPrec);
			return NULL;
		}
		int respComp = compVector(x, xPrec);
		if(respComp == 1) {
			printf("\033[1;32m");
			printf("Converge at iteration %d\n", i);
			printf("\033[0m");
			freeMemVEC(xPrec);
			return x;
		} else if( respComp == -1) {
			printf("\033[1;31m");
			printf("respComp = -1\n");
			printf("Error in Convergence\n");
			printf("\033[0m");
			freeMemVEC(xPrec);
			freeMemVEC(x);
			return NULL;
		}
		freeMemVEC(xPrec);
		xPrec = NULL;
	}
	printf("\033[1;31m");
	printf("No convergence\n");
	printf("\033[0m");
	freeMemVEC(x);
	return NULL;
}
