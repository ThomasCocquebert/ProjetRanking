#include "stdlib.h"
#include "stdio.h"
#include "time.h"
#include "../lib/structure.h"
#include "../lib/lecture.h"
#include "../lib/alteration.h"

int main() {
	srand(time(0));
	double temps = 0;
	int tempsInit = clock();
	FILE* fichier = NULL;
	fichier = fopen("Graphe/wb-cs-stanford.txt", "r+");
	if (fichier != NULL)
    {
	printf("Lecture du graphe\n");
	int NombreArcs = NBarcs(fichier);
	int NombreSommets = NBsommets(fichier);
	printf("Nb Arc : %d\n", NombreArcs);
	printf("Nb Sommets : %d\n", NombreSommets);
	Liste* tab = LectureFichier(fichier, NombreSommets);
	int j = delColumn(tab, NombreSommets);
	printf("Deleted columns : %d\n", j);
	printf("Libération de la structure\n");
	freeTableau(tab, NombreSommets);
	int tempsFin = clock();
	temps = (float)(tempsFin-tempsInit)/CLOCKS_PER_SEC;
	printf("\033[1;32m");
    printf("Temps d'execution = %lf ms\n", temps);
	printf("\033[0m");
	}
    else
    {
		printf("Impossible d'ouvrir le graphe\n");
		return 0;
    }
    return 0;
}