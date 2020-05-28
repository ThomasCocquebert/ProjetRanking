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
	fichier = fopen("Graphe/wikipedia.txt", "r+");
	if (fichier != NULL)
    {
	printf("Lecture du graphe\n");
	int NombreArcs = NBarcs(fichier);
	int NombreSommets = NBsommets(fichier);
	printf("Nb Arc : %d\n", NombreArcs);
	printf("Nb Sommets : %d\n", NombreSommets);
	Liste* tab = LectureFichier(fichier, NombreSommets);
	//~ afficherTableau(tab,NombreSommets);
	printf("Suppression ");
	//~ int j = delColumn(tab, NombreSommets);
	int j= delArc(tab,NombreSommets,2);
	//~ Liste* l1 = initListe();
	
	//~ Sommet* s1 = initSommet(3,5,0.5);
	//~ Sommet* s2 = initSommet(4,5,0.5);
	//~ Sommet* s3 = initSommet(5,5,0.5);
	//~ Sommet* s4 = initSommet(6,5,0.5);
	//~ Sommet* s5 = initSommet(7,5,0.5);
	//~ Sommet* s6 = initSommet(8,5,0.5);
	//~ Sommet* s7 = initSommet(9,5,0.5);
	//~ Sommet* s8 = initSommet(10,5,0.5);
	
	//~ ajouterSommet(l1,s1);
	//~ ajouterSommet(l1,s2);
	//~ ajouterSommet(l1,s3);
	//~ ajouterSommet(l1,s4);
	//~ ajouterSommet(l1,s5);
	//~ ajouterSommet(l1,s6);
	//~ ajouterSommet(l1,s7);
	//~ ajouterSommet(l1,s8);
	//~ afficherListe(l1);
	
	//~ deleteSommet(l1,3);
	//~ deleteSommet(l1,5);
	//~ deleteSommet(l1,8);
	//~ deleteSommet(l1,7);
	//~ deleteSommet(l1,5);
	
	//~ afficherListe(l1);

	//~ freeListe(l1);
	//~ free(l1);
	//~ afficherTableau(tab,NombreSommets);
	printf("Deleted arcs : %d\n", j);
	//~ printf("Deleted columns : %d\n", j);
	printf("Libération de la structure\n");
	freeTableau(tab, NombreSommets);
	int tempsFin = clock();
	temps = (float)(tempsFin-tempsInit)/CLOCKS_PER_SEC;
	printf("\033[1;32m");
    printf("Temps d'execution = %lf ms\n", temps);
	printf("\033[0m");
	//~ fclose(fichier);
	}
    else
    {
		printf("Impossible d'ouvrir le graphe\n");
		return 0;
    }
    return 0;
}
