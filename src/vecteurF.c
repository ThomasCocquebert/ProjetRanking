#include "stdlib.h"
#include "stdio.h"


Sommet * findSommetLigne(Liste * tab, int ligne) {
	Sommet * temp = tab->first;
	while (temp->numLigne!= ligne) {
		temp = temp->suivant;
	}
	return temp;
}

VEC * computeF(Liste * tab, int taille) {
	VEC* f = NULL;
	int i = 0;
	int j = 0;
	double somme = 0;
	initVECNull(f, taille); 
	
	//pour chaque ligne
	for (i=0; i<taille; i++) {
		//pour chaque colonne
		for (j = 0; somme == 0; j++) {
			somme += findSommetLigne(&tab[j],i)->proba;
		}
		if (somme == 0) {
			f->array[i] = 1;
		}
		
	}
	
	return f;
}
