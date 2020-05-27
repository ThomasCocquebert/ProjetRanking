#include "stdlib.h"
#include "stdio.h"
#include "time.h"
#include "../lib/structure.h"
#include "../lib/alteration.h"

int genNumber() {
	return (rand()%(100));
}

int testDel() {
	if(genNumber() <10) {
		return 1;
	}
	return 0;
}

int delLigne(Liste *tab, int ligne,int taille) {
	
	if(tab == NULL) {
		printf("\033[1;31m");
		printf("tab uninitialized\n");
		printf("Error in delColumn\n");
		printf("\033[0m");
		return -1;
	}
	
	Sommet* temp = NULL;
	Sommet* tempPrec = NULL;
	
	//parcours de chaque liste de colonne
	for(int i = 0; i<taille; i++) {
		
		//verif colonne supprimée + liste vide
		if(tab[i].exist == 1 && tab[i].first !=NULL) {
			
			printf("COLONNE %d\n",i);			
			temp = tab[i].first;
			tempPrec = NULL;
			
			while (temp->suivant!= NULL && temp->numLigne < ligne) {
				printf("element suivant\n");
				tempPrec = temp;
				temp = temp->suivant;
			}	
			afficherSommet(temp);
			
			if (temp->numLigne == ligne) {
				tempPrec->suivant = temp->suivant;
				freeSommet(temp);
			}
			
				
		}
			
		
	}
	
	return 1;
	
	
}

int delColumn(Liste* tab, int size) {
	if(tab == NULL) {
		printf("\033[1;31m");
		printf("tab uninitialized\n");
		printf("Error in delColumn\n");
		printf("\033[0m");
		return -1;
	}
	int j = 0;
	for(int i = 0; i < size; i++) {
		if(testDel()) {
			printf("Delete column %d.\n",i);
			j++;
			freeListe(&tab[i]);
			tab[i].first = NULL;
			tab[i].exist = 0;
			delLigne(tab, i, size);
		}
	}
	return j;
}

