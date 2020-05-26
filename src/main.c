#include "stdio.h"
#include "stdlib.h"
#include "time.h"
#include "../lib/structure.h"
#include "../lib/lecture.h"
#include "../lib/vector.h"
#include "../lib/calcul.h"
#include "../lib/alteration.h"

int main(int argc, char** argv) {
	if (argc == 1) {
		printf("Veuillez spécifier un graphe à ouvrir\n");
		exit(1);
	} else if (argc > 2) {
		printf("Trop d'arguments\n");
		exit(1);
	}
	double temps = 0;
	time_t tempsInit = clock();
	FILE* fichier = NULL;
	fichier = fopen(argv[1], "r+");
	if (fichier == NULL) {
		printf("Impossible d'ouvrir le graphe\n");
		exit(1);
	} 
	printf("Lecture du graphe\n");
	int NombreArcs = NBarcs(fichier);
	int NombreSommets = NBsommets(fichier);
	printf("Graphe : %s\n", argv[1]);
	printf("Nb Arc : %d\n", NombreArcs);
	printf("Nb Sommets : %d\n", NombreSommets);
	Liste* tab = LectureFichier(fichier, NombreSommets);
	printf("Libération de la structure\n");
	freeTableau(tab, NombreSommets);
	time_t tempsFin = clock();
	temps = (float)(tempsFin-tempsInit)/CLOCKS_PER_SEC;
	printf("\033[1;32m");
	printf("Temps d'execution = %lf ms\n", temps);
	printf("\033[0m");
	exit(0);
}