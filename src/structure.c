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
	Liste *suivant;
	Sommet *first;
	Sommet *last;
};

typedef struct Colonne Colonne;
struct Colonne
{
	Liste *first;
	Liste *last;
	
};


Liste* initListe(){
	Liste* l = malloc(sizeof(Liste));
	if (l == NULL) {
		printf("Erreur d'allocation liste\n");
		exit(1);
	}
	l->suivant = NULL;
	l->first = NULL;
	l->last = NULL;
	return l;
}

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
	return s;
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
}

void freeSommet(Sommet* s) {
	free(s);
}

void freeListe(Liste *l) {
	if (l->first == NULL){
		free(l);
		return;
	}
	Sommet* temp;
	temp = l->first;
	free(l->first);
	while(temp != NULL) {
		temp = temp->suivant;
		free(temp->suivant);
	}
}



int main(int argc, char** argv ){
	
	Colonne* c = initColonne();
	//~ printf("Hello world!\n");
	Liste* l = initListe();
	Liste* l2 = initListe();
	//~ l = initListe();
	Sommet* s1 = initSommet(1,1,0.5);
	Sommet* s2 = initSommet(2,1,0.7);
	ajouterSommet(l,s1);
	ajouterSommet(l,s2);
	
	Sommet* s3 = initSommet(2,1,0.7);
	Sommet* s4 = initSommet(2,1,0.7);
	ajouterSommet(l2,s3);
	ajouterSommet(l2,s4);
	
	ajouterListe(c,l);
	ajouterListe(c,l2);
	
	afficherColonne(c);
	//~ afficherListe(l);
	//~ afficherListe(l2);
	

	//~ afficherSommet(s1);

	//~ ajouterSommet(l,s2);
	//~ ajouterSommet(l,s3);
	//~ ajouterSommet(l,s4);
	//~ freeListe(l);
	
	//~ afficherListe(l);
    return 0;
	
}
