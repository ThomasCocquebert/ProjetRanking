#include "stdlib.h"
#include "stdio.h"

typedef struct Sommet Sommet;
struct Sommet
{
    int numLigne;
    int numColonne;
    double proba;
    Sommet *suivant;
};

typedef struct Liste Liste;
struct Liste
{	
	Sommet *first;
	Sommet *last;
};
/*
typedef struct Colonne Colonne;
struct Colonne
{
	Liste *first;
	Liste *last;
	
};
*/

Liste* initListe(){
	Liste* l = malloc(sizeof(Liste));
	if (l == NULL) {
		printf("Erreur d'allocation liste\n");
		exit(1);
	}
	l->first = NULL;
	l->last = NULL;
	return l;
}
/*
Colonne* initColonne(){
	Colonne* c = malloc(sizeof(Colonne));
	if (c == NULL) {
		printf("Erreur d'allocation colonne\n");
		exit(1);
	}
	c->first = NULL;
	c->last = NULL;
	return c;
}
*/
Sommet* initSommet(int ligne,int colonne,double proba)
{
	Sommet* s = malloc(sizeof(Sommet));
	if (s == NULL) {
		printf("Erreur d'allocation\n");
		exit(0);
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
	}
	if (tab == NULL) {
		printf("Erreur allocation tableau");
		exit(1);
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
	/*
void ajouterListe(Colonne* c,Liste *new) {
	//si ajout sur liste vide:
	if (c == NULL) {
		printf("erreur: tentative ajout sur une liste vide");
		exit(1);
	}
	//si liste vide:
	if (c->first == NULL) {
		c->first = new;
		c->first->suivant = NULL;
		c->last = new;
	}
	//ajout à la fin
	else {
		
		c->last->suivant = new;
		c->last = c->last->suivant;
		}
		
	}		
	*/
	

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
/*
void afficherColonne(Colonne* c) {
	printf("****AFFICHAGE Colonne:\n");
	//si liste vide
	if (c->first == NULL) {
		printf("liste vide\n");
	}
	else {
		Liste* current = c->first;
		while (current != NULL) {
			afficherListe(current);
			current = current->suivant;
		}
		
	}
}*/

void afficherTableau(Liste *tab, int taille) {
	printf("=======AFFICHAGE TABLEAU=========\n\n");
	for(int i = 0; i<taille; i++) {
		printf("******n°colone :%d\n",i);
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
		printf("HERE");
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

/*
int main(int argc, char** argv ){
	int nombre = 3;

	Liste* tab = initTableau(nombre);
	
	Sommet* s1 = initSommet(2,1,0.7);
	Sommet* s2 = initSommet(2,1,0.5);
	
	Sommet* s3 = initSommet(2,1,0.8);
	Sommet* s4 = initSommet(2,1,0.88);
	
	ajouterSommet(&tab[0],s1);
	ajouterSommet(&tab[0],s2);
	
	ajouterSommet(&tab[1],s3);
	ajouterSommet(&tab[2],s4);
	
	afficherTableau(tab,nombre);
	freeTableau(tab,nombre);
	
    return 0;
	
}
*/
