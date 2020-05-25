#include "stdio.h"
#include "stdlib.h"

void LectureFichier(){
	FILE* fichier = NULL;
    char caractereActuel;
    int NombreArcs;
    int NombreSommets;
    int NumeroLigne;
    int NbArcsLigne;
    int Colonne;
	double Valeur;
    int i;
    int j;
     fichier = fopen("web1.txt", "r+");
    if (fichier != NULL)
    {
		fscanf(fichier, "%d", &NombreArcs);			//Lecture de la première valeur du fichier
		fscanf(fichier, "%d", &NombreSommets);			//Nombre de sommets de la matrice
        printf("%d \n", NombreArcs);
        printf("%d \n", NombreSommets);
        
		for(i = 0; i < NombreSommets; i++){
            fscanf(fichier, "%d", &NumeroLigne);		//Numéro de la ligne actuellement lu dans le fichier
            fscanf(fichier, "%d", &NbArcsLigne);		//Nombre d'arcs pour cette ligne
            printf("%d %d", NumeroLigne, NbArcsLigne);
            for(j = 0; j < NbArcsLigne; j++){
				fscanf(fichier, "%d %lf", &Colonne, &Valeur);	//Recupération pour chaque arc de la ligne de sa destination et de sa colonne
				printf(" %d %lf", Colonne, Valeur);
			}
			printf("\n");
        } 
     
     fclose(fichier);   		//Fermeture du fichier
    }
    else
    {
        printf("Impossible d'ouvrir le fichier test.txt");
    }
}

int main(){
	
	LectureFichier();
    return 0;
}
