#include "stdlib.h"
#include "stdio.h"
#include "time.h"
#include "../lib/vector.h"
#include "../lib/structure.h"
#include "../lib/lecture.h"

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
	//printf("Check Fonction\n");
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
	freeMemVEC(pi);
	return res;
}

int main(int argc, char *argv[]) {
	double temps = 0;
	int tempsInit = clock();
	char *Chemin = argv[1];
	FILE* fichier = NULL;
	fichier = fopen(Chemin, "r+");
	if (fichier != NULL)
    {
	printf("Lecture du graphe\n");
	int NombreArcs = NBarcs(fichier);
	int NombreSommets = NBsommets(fichier);
	Liste* tab = LectureFichier(fichier, NombreSommets);
	//~ afficherTableau(tab, NombreSommets);
	VEC* pi = malloc(sizeof(VEC));
	initVEC(pi, NombreSommets);
	VEC* pi2 = computePiG(tab, pi, NombreSommets);
	printVEC(pi2);
	freeMemVEC(pi2);
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
