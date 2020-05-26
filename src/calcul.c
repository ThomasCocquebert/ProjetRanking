#include "stdlib.h"
#include "stdio.h"
#include "time.h"
#include "../lib/vector.h"
#include "../lib/structure.h"
#include "../lib/lecture.h"
#include "../lib/calcul.h"

VEC * computeF(Liste * tab, int taille) {
	VEC* f = NULL;
	int i = 0;
	initVECNull(f, taille); 
	
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

VEC* computePageRank(Liste * tab, VEC* x,int taille) {
	VEC* pageRank = NULL;
	initVECNull(pageRank,pageRank);
	
	VEC* ancientX;
	VEC* aXp = NULL;
	
	VEC* scalaire1 = NULL;
	initVECe(scalaire1,taille);
	VEC* scalaire2 = NULL;
	initVECe(scalaire2,taille);
	VECByDouble(scalaire2,0.15/taille);
	
	VEC* e = NULL;
	initVECe(e,taille);
	
	double xFt;
	do {
		
		free(pageRank);
		initVECe(pageRank,taille);
		xFt = VxVt(x,computeF(tab,taille));
		//premiere partie
		computePiG(tab,x,taille);
		VECByDouble(aXp, 0.85);
		
		//deuxieme partie
		
		freeMemVEC(scalaire1);
		initVECe(scalaire1,taille);
		VECByDouble(scalaire1,0.85*xFt);
		
		//calcul
		VEC=

			
	}
	while( compVector(ancientX, pageRank) == 0);
	
	
	return pageRank;
	
}
int convergeTest(Liste* tab, int size) {
	int nbIt = 0;
	VEC* xNext = malloc(sizeof(VEC));
	if(xNext == NULL) {
		printf("\033[1;31m");
		printf("Allocation of VEC failed\n");
		printf("\033[0m");
		return -1;
	}
	if(!initVEC(xNext, size)) {
		free(xNext);
		return -1;
	}
	VEC* x = NULL;
	for(int i = 0; i < 1000; i++) {
		x = xNext;
		xNext = computePiG(tab, xNext, size);
		if(xNext == NULL) {
			return -1;
		}
		if(compVector(x, xNext)) {
			nbIt = i+1;
			printf("\033[1;32m");
			printf("Number of iteration before convergence : %d\n", nbIt);
			printf("\033[0m");
			freeMemVEC(xNext);
			freeMemVEC(x);
			return 1;
		}
		freeMemVEC(x);
		x = NULL;
	}
	freeMemVEC(xNext);
	printf("\033[1;31m");
	printf("No convergence\n");
	printf("\033[0m");
	return 0;
}


int main(int argc, char *argv[]) {
	printf("Check\n");
	double temps = 0;
	int tempsInit = clock();
	char *Chemin = argv[1];
	FILE* fichier = NULL;
	printf("Check file\n");
	fichier = fopen(Chemin, "r+");
	if (fichier != NULL)
    {
	printf("Lecture du graphe\n");
	int NombreArcs = NBarcs(fichier);
	int NombreSommets = NBsommets(fichier);
	Liste* tab = LectureFichier(fichier, NombreSommets);
	convergeTest(tab, NombreSommets);
	printf("Libération de la structure\n");
	freeTableau(tab, NombreSommets);
	int tempsFin = clock();		//Temps d'execution du programme
	temps = (float)(tempsFin-tempsInit)/CLOCKS_PER_SEC;
	printf("\033[1;32m");
    printf("Temps d'execution = %lf s\n", temps);
	printf("\033[0m");
	}
    else
    {
		printf("Impossible d'ouvrir le graphe\n");
		return 0;
    }
    return 0;
}
