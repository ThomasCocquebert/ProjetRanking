#include "stdio.h"
#include "stdlib.h"
#include "time.h"
#include "../lib/structure.h"

int NBarcs(FILE* fichier){
	int NombreArcs;
	fscanf(fichier, "%d", &NombreArcs);			//Lecture de la première valeur du fichier
	//~ printf("%d \n", NombreArcs);
	return NombreArcs;
}

int NBsommets(FILE* fichier){
	int NombreSommets;
	fscanf(fichier, "%d", &NombreSommets);			//Nombre de sommets de la matrice
	//~ printf("%d \n", NombreSommets);
    return NombreSommets;
}


Liste* LectureFichier(FILE* fichier, int NombreSommets){
	
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
            //~ printf("%d %d", NumeroLigne, NbArcsLigne);
            for(j = 0; j < NbArcsLigne; j++){
				fscanf(fichier, "%d %lf", &Colonne, &Valeur);	//Recupération pour chaque arc de la ligne de sa destination et de sa colonne
				Sommet *s = initSommet( NumeroLigne-1, Colonne-1, Valeur);
				ajouterSommet(&tab[Colonne-1],s);
				//~ printf(" %d %lf", Colonne, Valeur);
			}
			//~ printf("\n");
        } 
     fclose(fichier);   		//Fermeture du fichier
     return tab;
}

