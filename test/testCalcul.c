#include "stdlib.h"
#include "stdio.h"
#include "time.h"
#include "../lib/vector.h"
#include "../lib/structure.h"
#include "../lib/lecture.h"
#include "../lib/calcul.h"

int main(int argc, char **argv) {
	printf("Check\n");
	double temps = 0;
	int tempsInit = clock();
	//char *Chemin = argv[1];
	FILE* fichier = NULL;
	printf("Check file\n");
	fichier = fopen("Graphe/web1.txt", "r+");
	if (fichier != NULL)
    {
	printf("Lecture du graphe\n");
	int NombreArcs = NBarcs(fichier);
	int NombreSommets = NBsommets(fichier);
	printf("Nb Arc : %d\n", NombreArcs);
	printf("Nb Sommets : %d\n", NombreSommets);
	Liste* tab = LectureFichier(fichier, NombreSommets);
	//~ convergeTest(tab, NombreSommets);
	VEC* x = malloc(sizeof(VEC));
	initVEC(x, NombreSommets);
	//VEC* pr = PageRank(tab, x, NombreSommets);
	//printVEC(pr);
	Convergence(tab, x, NombreSommets);
	printf("Libération de la structure\n");
	freeTableau(tab, NombreSommets);
	//freeMemVEC(pr);
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