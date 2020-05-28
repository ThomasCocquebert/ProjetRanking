#include "stdlib.h"
#include "stdio.h"
#include "time.h"
#include "../lib/structure.h"
#include "../lib/vector.h"
#include "../lib/lecture.h"
#include "../lib/calcul.h"

int main(int argc, char **argv) {
	FILE* fichier = NULL;
	fichier = fopen("Graphe/web1.txt", "r+");
	if (fichier != NULL)
    {
	printf("Lecture du graphe\n");
	int NombreArcs = NBarcs(fichier);
	int NombreSommets = NBsommets(fichier);
	printf("Nb Arc : %d\n", NombreArcs);
	printf("Nb Sommets : %d\n", NombreSommets);
	Liste* tab = LectureFichier(fichier, NombreSommets);
	afficherTableau(tab, NombreSommets);
	//VEC* x = malloc(sizeof(VEC));
	//initVEC(x, NombreSommets);
	VEC* ft = computeF(tab, NombreSommets);
	printVEC(ft);
	freeMemVEC(ft);
	ft = NULL;
	//x = Convergence(tab, x, NombreSommets);
	tab[2].exist = 0;
	tab[3].exist = 0;
	tab[4].exist = 0;
	ft = computeF(tab, NombreSommets-3);
	printVEC(ft);
	freeMemVEC(ft);

	VEC* x2 = malloc(sizeof(VEC));
	initVEC(x2, NombreSommets-3);
	printf("x2\n");
	printVEC(x2);
	VEC* piG = computePiG(tab, x2, NombreSommets-3);
	printf("piG\n");
	printVEC(piG);
	freeMemVEC(x2);
	freeMemVEC(piG);
	freeTableau(tab, NombreSommets);
	//freeMemVEC(x);
	}
    else
    {
		printf("Impossible d'ouvrir le graphe\n");
		return 0;
    }
    return 0;
}