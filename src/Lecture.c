#include "stdio.h"
#include "stdlib.h"
#include "time.h"
#include "structure.c"

int NBsommets(FILE* fichier){
	int NombreArcs;
	int NombreSommets;
	fscanf(fichier, "%d", &NombreArcs);			//Lecture de la première valeur du fichier
	fscanf(fichier, "%d", &NombreSommets);			//Nombre de sommets de la matrice
	printf("%d \n", NombreArcs);
    printf("%d \n", NombreSommets);
    return NombreSommets;
}


Liste* LectureFichier(FILE* fichier, int NombreSommets){
	
    char caractereActuel;
    int NombreArcs;
    int NumeroLigne;
    int NbArcsLigne;
    int Colonne;
	double Valeur;
    int i;
    int j;
    
	Liste* tab = initTableau(NombreSommets);        
	for(i = 0; i < NombreSommets; i++){
            fscanf(fichier, "%d", &NumeroLigne);		//Numéro de la ligne actuellement lu dans le fichier
            fscanf(fichier, "%d", &NbArcsLigne);		//Nombre d'arcs pour cette ligne
            printf("%d %d", NumeroLigne, NbArcsLigne);
            for(j = 0; j < NbArcsLigne; j++){
				fscanf(fichier, "%d %lf", &Colonne, &Valeur);	//Recupération pour chaque arc de la ligne de sa destination et de sa colonne
				Sommet *s = initSommet( NumeroLigne-1, Colonne-1, Valeur);
				ajouterSommet(&tab[Colonne-1],s);
				printf(" %d %lf", Colonne, Valeur);
			}
			printf("\n");
        } 
     fclose(fichier);   		//Fermeture du fichier
     return tab;
}

int main(){
	int time = 0;
	char *Chemin = "../Graphe/web1.txt";
	FILE* fichier = NULL;
	fichier = fopen(Chemin, "r+");
	if (fichier != NULL)
    {
	int NombreSommets = NBsommets(fichier);
	Liste* tab = LectureFichier(fichier, NombreSommets);
	afficherTableau(tab,NombreSommets);
	freeTableau(tab, NombreSommets);
	time = clock();		//Temps d'execution du programme
	printf("\033[1;32m");
    printf("Temps d'execution = %d ms\n", time);
	printf("\033[0m");
	}
    else
    {
		printf("Impossible d'ouvrir le graphe");
		return 0;
    }
    return 0;
}
