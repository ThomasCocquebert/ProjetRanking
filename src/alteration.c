#include "stdlib.h"
#include "stdio.h"
#include "time.h"
#include "../lib/structure.h"
#include "../lib/alteration.h"

int genNumber() {
	return (rand()%(100));
}

int testDel(int percentage) {
	if(genNumber() < percentage) {
		return 1;
	}
	return 0;
}

int delLigne(Liste *tab, int ligne,int taille) {
	
	if(tab == NULL) {
		printf("\033[1;31m");
		printf("tab uninitialized\n");
		printf("Error in delLigne\n");
		printf("\033[0m");
		return -1;
	}
	
	Sommet* temp = NULL;
	Sommet* tempPrec = NULL;
	
	//parcours de chaque liste de colonne
	for(int i = 0; i<taille; i++) {
		
		//verif colonne supprimée + liste vide
		if(tab[i].exist == 1 && tab[i].first !=NULL) {
			
			//~ printf("COLONNE %d\n",i);			
			temp = tab[i].first;
			tempPrec = tab[i].first;
			
			while (temp->suivant!= NULL && temp->numLigne < ligne) {
				//~ printf("element suivant\n");
				tempPrec = temp;
				temp = temp->suivant;
			}	
			//~ afficherSommet(temp);
			
			
			if (temp->numLigne == ligne && tempPrec != temp) {
				//~ printf("TEMPPREC\n");
				//afficherSommet(tempPrec);
				tempPrec->suivant = temp->suivant;
				
				//si on est arriveé au dernier élément, on modifie le last de la liste
				if (temp->suivant == NULL) {
					tab[i].last = tempPrec;
				}
				
				temp->suivant = NULL;
				freeSommet(temp);
				
			}
			else if (temp->numLigne == ligne){
				temp->suivant = NULL;
				freeSommet(temp);
				tab[i].first = NULL;
				tab[i].last = NULL;
				
			}
			
				
		}
			
		
	}
	return 1;
	
	
}


void deleteSommet(Liste* liste, int ligne) {
	
	if (liste == NULL) {
		return;
	}	
	else if ( liste->first == NULL) {
		return;
	}
	
	Sommet* tmp = liste->first;
	Sommet* prec = liste->first;
	
	//on trouve le sommet à supprimer
	while (tmp->numLigne<ligne && tmp->suivant!=NULL) {
		//~ printf("num ligne :%d\n",tmp->numLigne);
		prec = tmp;
		tmp = tmp->suivant;
	}
	
	if (tmp->numLigne == ligne) {
		//si c'est le premier
		if (tmp == liste->first) {
			//~ printf("PREMIER PAS FINI\n");
			liste->first = tmp->suivant;
			free(tmp);
		}
		//pas arrivé à la fin
		else if (tmp->suivant!= NULL) {
			//~ printf("PAS A LA FIN\n");
			prec->suivant = tmp->suivant;
			free(tmp);
		}
		//arrivé à la fin mais pas qu'un seul élément ds la liste
		else if (tmp->suivant == NULL 
					&& tmp!=liste->first) {
			//~ printf("FIN\n");
			liste->last = prec;
			liste->last->suivant = NULL;
			free(tmp);
			
		}
		//qu'un seul élément dans la liste
		else if (tmp->suivant == NULL 
					&& tmp==liste->first) {
			//~ printf("PREMIER\n");
			liste->last = NULL;
			liste->first = NULL;
			free(tmp);
			
		}
	}
	
}
int delLigne2(Liste *tab, int ligne, int taille) {
	if(tab == NULL) {
		printf("\033[1;31m");
		printf("tab uninitialized\n");
		printf("Error in delLigne\n");
		printf("\033[0m");
		return -1;
	}
	
	for (int i = 0; i<taille; i++) {
		if (tab[i].exist == 1) {
		deleteSommet(&tab[i],ligne);
		}
	}
	
	return 0;
	
}


int delColumn(Liste* tab, int size, int percentage) {
	if(tab == NULL) {
		printf("\033[1;31m");
		printf("tab uninitialized\n");
		printf("Error in delColumn\n");
		printf("\033[0m");
		return -1;
	}
	int j = 0;
	for(int i = 0; i < size; i++) {
		tab[i].newCol = tab[i].newCol - j;
		if(testDel(percentage)) {
			j++;
			tab[i].exist = 0;
		}
	}
	return j;
}

int delArcListe(Liste* liste, int perc) {
	if (liste->first == NULL 
			|| liste->first->suivant == NULL
			|| liste->exist == 0) {
				return 0;
			}
			
	Sommet* tmp = liste->first;
	Sommet* tmpPrec = liste->first;
	int cpt = 0;
	
	while (tmp->suivant!=NULL) {
		
		tmpPrec = tmp;
		tmp = tmp->suivant;
		if ( testDel(perc) == 1) {
			cpt++;
			//~ printf("DELETE SOMMET:\n");
			//~ afficherSommet(tmp);
			//si c'est le dernier
					
			if (tmp->suivant == NULL) {
				liste->last = tmpPrec;
				tmpPrec->suivant = NULL;				
				free(tmp); 
				tmp = tmpPrec; 
			}
			//si c'est pas le dernier
			else {
				tmpPrec->suivant=tmp->suivant;
				free(tmp);
				tmp = tmpPrec; 
			}
			
			
			
		}
	
	}
	
	return cpt;
}
int delArc(Liste* tab, int size,int perc) {
	if(tab == NULL) {
		printf("\033[1;31m");
		printf("tab uninitialized\n");
		printf("Error in delArc\n");
		printf("\033[0m");
		return -1;
	}
	
	int j = 0;
	for(int i = 0; i < size; i++) {
		j+= delArcListe(&tab[i],perc);

	}
	
	return j;
	
}

int delColumnArc(Liste* tab, int size, int pColumn, int pArc) {
	if(tab == NULL) {
		printf("\033[1;31m");
		printf("tab uninitialized\n");
		printf("Error in delColumnArc\n");
		printf("\033[0m");
		return -1;
	}
	int j = 0;
	for(int i = 0; i < size; i++) {
		tab[i].newCol = tab[i].newCol - j;
		if(testDel(pColumn)) {
			j++;
			tab[i].exist = 0;
		}
		else {
			j+= delArcListe(&tab[i], pArc);
		}
		
	}
	return j;
}


