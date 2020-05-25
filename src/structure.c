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

Liste* initListe(){
	Liste* l = malloc(sizeof(Liste*));
	if (l == NULL) {
		printf("Erreur d'allocation liste\n");
		exit(0);
	}
	l->first = NULL;
	l->last = NULL;
	return l;
}

Sommet* initSommet(int ligne,int colonne,double proba)
{
	Sommet* s = malloc(sizeof(Sommet*));
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
	
	

void afficherSommet(Sommet* s) {
	printf("Sommet: numLigne=%d, numcolonne=%d, proba=%lf\n", 
		s->numLigne, s->numColonne, s->proba);
}

void afficherListe(Liste* l) {
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

void freeSommet(Sommet* s) {
	free(s);
}

void freeListe(Liste *l) {
	Sommet* temp;
	temp = l->first;
	free(l->first);
	while(temp != NULL) {
		temp = temp->suivant;
		free(temp->suivant);
	}
}




int main(int argc, char** argv ){
	
	printf("Hello world!\n");
	Liste* l = initListe();
	//~ l = initListe();
	//~ Sommet* s1 = initSommet(1,1,0.5);
	//~ Sommet* s2 = initSommet(2,1,0.7);
	//~ Sommet* s3 = initSommet(2,1,0.7);
	//~ Sommet* s4 = initSommet(2,1,0.7);
	//~ afficherSommet(s2);
	//~ afficherSommet(s1);
	//~ ajouterSommet(l,s1);
	//~ ajouterSommet(l,s2);
	//~ ajouterSommet(l,s3);
	//~ ajouterSommet(l,s4);
	
	afficherListe(l);
    return 0;
	
}
