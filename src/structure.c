#include "stdlib.h"
#include "stdio.h"
#include "../lib/structure.h"

Liste* initListe(){
	Liste* l = malloc(sizeof(Liste));
	if (l == NULL) {
		printf("\033[1;31m");
		printf("Erreur d'allocation liste\n");
		printf("Erreur dans initList\n");
		printf("\033[0m");
		return NULL;
	}
	l->first = NULL;
	l->last = NULL;
	return l;
}

Sommet* initSommet(int ligne,int colonne,double proba)
{
	Sommet* s = malloc(sizeof(Sommet));
	if (s == NULL) {
		printf("\033[1;31m");
		printf("Erreur d'allocation sommet\n");
		printf("Erreur dans initSommet\n");
		printf("\033[0m");
		return NULL;
	}
	s->numLigne = ligne;
	s->numColonne = colonne;
	s->proba = proba;
	s->suivant = NULL;
	return s;
}

Liste* initTableau(int nb) {
	Liste* tab = malloc(nb * sizeof(Liste));
	for (int i = 0; i<nb; i++) {
		tab[i].first = NULL;
		tab[i].last = NULL;
		tab[i].exist = 1;
	}
	if (tab == NULL) {
		printf("\033[1;31m");
		printf("Erreur allocation tab");
		printf("Erreur dans initTableau\n");
		printf("\033[0m");
		return NULL;
	}
	return tab;
}
void ajouterSommet(Liste *l,Sommet* s) {
	//si liste vide:
	if (l->first == NULL) {
		l->first = s;
		l->first->suivant = NULL;
		l->last = s;
	}
	//ajout à la fin
	else {
		
		l->last->suivant = s;
		l->last = l->last->suivant;
		}
		
	}

void afficherSommet(Sommet* s) {
	printf("Sommet: numLigne=%d, numcolonne=%d, proba=%lf\n", 
		s->numLigne, s->numColonne, s->proba);
}

void afficherListe(Liste* l) {
	printf("AFFICHAGE LISTE:\n");
	//si liste vide
	if (l->first == NULL) {
		printf("liste vide\n");
	}
	else {
		Sommet* current = l->first;
		while (current != NULL) {
			afficherSommet(current);
			current = current->suivant;
		}
		
	}
}

void afficherTableau(Liste *tab, int taille) {
	printf("=======AFFICHAGE TABLEAU=========\n\n");
	for(int i = 0; i<taille; i++) {
		printf("******n°colonne :%d\n",i);
		afficherListe(&tab[i]);
		printf("******\n\n");
	}
	
	printf("=================================\n\n");
}

void freeSommet(Sommet* s) {
	free(s);
}

void freeListe(Liste *l) {
	if (l->first == NULL){
		return;
	}
	Sommet* temp = NULL;
	while(l->first->suivant != NULL) {
		temp = l->first;
		l->first = l->first->suivant;
		free(temp);
	}
	free(l->first);
	
}

void freeTableau(Liste * tab,int taille) {
	for (int i = 0; i<taille; i++) {
		freeListe(&tab[i]);
	}
	free(tab);
	
}