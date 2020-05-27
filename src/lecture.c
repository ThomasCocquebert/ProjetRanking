#include "stdio.h"
#include "stdlib.h"
#include "time.h"
#include "../lib/structure.h"

int NBarcs(FILE* fichier){
	int NombreArcs;
	//Lecture de la première valeur du fichier
	fscanf(fichier, "%d", &NombreArcs);			
	return NombreArcs;
}

int NBsommets(FILE* fichier){
	int NombreSommets;
	//Nombre de sommets de la matrice
	fscanf(fichier, "%d", &NombreSommets);			
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
		//Numéro de la ligne actuellement lu dans le fichier
        fscanf(fichier, "%d", &NumeroLigne);
        //Nombre d'arcs pour cette ligne		
        fscanf(fichier, "%d", &NbArcsLigne);
            for(j = 0; j < NbArcsLigne; j++){
            	//Recupération pour chaque arc de la ligne de sa destination et de sa colonne
				fscanf(fichier, "%d %lf", &Colonne, &Valeur);
				Sommet *s = initSommet( NumeroLigne-1, Colonne-1, Valeur);
				ajouterSommet(&tab[Colonne-1],s);
			}
        }
    //Fermeture du fichier
    fclose(fichier);   		
    return tab;
}