#include "stdio.h"
#include "stdlib.h"
#include "time.h"
#include "../lib/structure.h"
#include "../lib/lecture.h"



int main(int argc, char *argv[]){
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
		//~ afficherTableau(tab,NombreSommets);
		printf("Libération de la structure\n");
		freeTableau(tab, NombreSommets);
		int tempsFin = clock();		//Temps d'execution du programme
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
