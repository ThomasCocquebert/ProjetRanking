#include "stdlib.h"
#include "stdio.h"


VEC * computeF(Liste * tab, int taille) {
	VEC* f = NULL;
	int i = 0;
	int j = 0;
	double somme = 0;
	initVECNull(f, taille); 
	
	//pour chaque colonne
	for (i=0; i<taille; i++) {
		//si pas délément ==> somme des probas = 0
		if (tab[i]->first == NULL) {
			f->array[i] = 1;
		}
		//elément ==> somme des probas > 0
		else {
			f->array[i] = 0;
		}
		
	}
	
	return f;
}
