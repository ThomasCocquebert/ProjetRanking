#include "stdlib.h"
#include "stdio.h"
#include "time.h"
#include "../lib/vector.h"
#include "../lib/structure.h"
#include "../lib/lecture.h"
#include "../lib/calcul.h"

VEC *computeF(Liste *tab, int taille) {
	VEC* f = malloc(sizeof(VEC));
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

VEC* computePageRank(Liste *tab, VEC* x,int taille,VEC* v) {
	CopyVector(x,v);
	
	VEC* pageRank = malloc(sizeof(VEC));
	initVECNull(pageRank,taille);
	
	VEC* F = malloc(sizeof(VEC));
	initVECe(F,taille);
	
	VEC* Partie2 = malloc(sizeof(VEC));
	initVECe(Partie2,taille);
	
	VEC* Partie3 = malloc(sizeof(VEC));
	initVECe(Partie3,taille);
	
	free(pageRank);
	pageRank = computePiG(tab, x, taille);		//Partie 1 du calcul: alpha*x*P
	VECByDouble(pageRank, 0.85);
	
	free(F);
	F = computeF(tab,taille);			//Partie 2 du calcul: alpha*(x*ftransposé)*e
	double scal = VxVt(x,F);
	scal = scal * 0.85;
	VECByDouble(Partie2, scal);
	
	double je = 0.15;		//Partie 3 du calcul: (1-alpha)/N * e
	je = je/taille;
	VECByDouble(Partie3, je);
	
	VECAddVector(pageRank, Partie2);	//Partie 1 + Partie 2
	VECAddVector(pageRank, Partie3);	//Partie 1 + 2 + 3
	//~ printVEC(pageRank);
	
	freeMemVEC(F);
	freeMemVEC(Partie2);
	freeMemVEC(Partie3);
    CopyVector(pageRank, v);
	freeMemVEC(pageRank);
	return v;
	
}

void Convergence(Liste* tab, VEC* x, int taille){

	int cpt = 0;
	double diff = 0;
	VEC* tmp = malloc(sizeof(VEC));
	initVECNull(tmp, taille);
	
	VEC* v = malloc(sizeof(VEC));
	initVECNull(v, taille);
	
	VEC* ancientX = malloc(sizeof(VEC));
	initVECNull(ancientX, taille);
	do{
		CopyVector(x, ancientX);
		freeMemVEC(x);
		x = computePageRank(tab, ancientX, taille,v);
		freeMemVEC(tmp);
		tmp = minusVector(x, ancientX);
		diff = Norme1(tmp);
		//~ printf("norme = %lf",diff);
		cpt++;
	}while(diff >= 0.000001);
	printf("Cpt = %d\n",cpt);
	printVEC(x);
	freeMemVEC(ancientX);
	freeMemVEC(tmp);
	freeMemVEC(v);
}

/*
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
}*/


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
	//~ convergeTest(tab, NombreSommets);
	VEC* x = malloc(sizeof(VEC));
	initVEC(x, NombreSommets);
	//~ computePageRank(tab, x, NombreSommets);
	Convergence(tab, x, NombreSommets);
	printf("Libération de la structure\n");
	freeTableau(tab, NombreSommets);
	freeMemVEC(x);
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
