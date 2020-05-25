#include "stdio.h"
#include "stdlib.h"
#include "time.h"
#include "structure.c"

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

int main(){
	double temps = 0;
	int tempsInit = clock();
	char *Chemin = "../Graphe/Stanford.txt";
	FILE* fichier = NULL;
	fichier = fopen(Chemin, "r+");
	if (fichier != NULL)
    {
	int NombreArcs = NBarcs(fichier);
	int NombreSommets = NBsommets(fichier);
	Liste* tab = LectureFichier(fichier, NombreSommets);
	//~ afficherTableau(tab,NombreSommets);
	freeTableau(tab, NombreSommets);
	int tempsFin = clock();		//Temps d'execution du programme
	temps = (float)(tempsFin-tempsInit)/CLOCKS_PER_SEC;
	printf("\033[1;32m");
    printf("Temps d'execution = %lf ms\n", temps);
	printf("\033[0m");
	}
    else
    {
		printf("Impossible d'ouvrir le graphe");
		return 0;
    }
    return 0;
}
