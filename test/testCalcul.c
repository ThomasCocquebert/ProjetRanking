#include "stdlib.h"
#include "stdio.h"
#include "time.h"
#include "../lib/structure.h"
#include "../lib/vector.h"
#include "../lib/lecture.h"
#include "../lib/calcul.h"
#include "../lib/alteration.h"

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

	int delCol = delColumn(tab, NombreSommets);
	printf("Sommet supprimés : %d\n", delCol);
	afficherTableau(tab, NombreSommets);
	
	
	VEC* f = computeF(tab, NombreSommets-delCol);
  	printVEC(f);
	
	VEC* x = malloc(sizeof(VEC));
	initVEC(x, NombreSommets-delCol);
	VEC* piG = computePiG(tab, x, NombreSommets-delCol);
	printVEC(piG);
	VEC* piG2 = computePiG(tab, piG, NombreSommets-delCol);
	printVEC(piG2);
	freeMemVEC(piG);
	freeMemVEC(piG2);
	freeMemVEC(f);
	freeMemVEC(x);
	freeTableau(tab, NombreSommets);
	}
    else
    {
		printf("Impossible d'ouvrir le graphe\n");
		return 0;
    }
    return 0;
}