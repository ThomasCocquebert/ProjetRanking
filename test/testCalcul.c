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
	//afficherTableau(tab, NombreSommets);

	//int delCol = delColumn(tab, NombreSommets);
	//printf("Sommet supprimés : %d\n", delCol);
	//afficherTableau(tab, NombreSommets);
	
	VEC* x = malloc(sizeof(VEC));
	initVEC(x, NombreSommets);
	x->array[0] = 0.12;
	x->array[1] = 0.15;
	x->array[2] = 0.09;
	x->array[3] = 0.24;
	x->array[4] = 0.12;
	x->array[5] = 0.08;
	x->array[6] = 0.1;
	x->array[7] = 0.1;
	//x = Convergence(tab, x, NombreSommets);

	VEC* norm = malloc(sizeof(VEC));
	initVECNull(norm, NombreSommets-3);

	tab[2].exist = 0;
	tab[3].exist = 0;
	tab[4].exist = 0;

	printVEC(x);
	NewVector(norm, x, tab);
	printVEC(norm);
	Normalisation(norm);
	printVEC(norm);

	freeMemVEC(x);
	freeMemVEC(norm);
	freeTableau(tab, NombreSommets);
	}
    else
    {
		printf("Impossible d'ouvrir le graphe\n");
		return 0;
    }
    return 0;
}