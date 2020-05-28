#ifndef STRUCTURE_H
#define STRUCTURE_H

/*
Structure for one node of the graph
numLigne : stored the row of the node
numColonne : stored the columne of the node
proba : stored the probability of the edge
suivant : the address of the next node in the list
*/
typedef struct Sommet Sommet;
struct Sommet
{
    int numLigne;
    int numColonne;
    double proba;
    Sommet *suivant;
};

/*
Liste : stored the first element of the columne
first : the adress of the first Sommet
last : the adress of the last Sommet
*/
typedef struct Liste Liste;
struct Liste
{	
	int exist;
	int newCol;
	Sommet *first;
	Sommet *last;
};

/*
Initilized a list
We use an array of list to stored each columne of our matrix
Return the address of the Liste or NULL if error
*/
Liste* initListe();

/*
Initialized a Sommet
ligne : the Sommet.numLigne value
colonne : the Sommet.numColonne value
proba : the Sommet.proba value
Return an adress of Sommet of NULL if error
*/
Sommet* initSommet(int ligne,int colonne,double proba);

/*
Initilized the array of Liste
nb : the number of Liste in the array
Return an array of liste address of NULL if error
*/
Liste* initTableau(int nb);

/*
Add a Sommet to a List
l : the list wich take the new Sommet
s : the Sommet to add to the Liste
*/
void ajouterSommet(Liste *l,Sommet* s);

/*
Print a Sommet
s : the sommet to print
*/
void afficherSommet(Sommet* s);

/*
Print a Liste
l : the Liste to print
*/
void afficherListe(Liste* l);

/*
Print an array of Liste
tab : the address of the array
taille : the size of the array
*/
void afficherTableau(Liste *tab, int taille);

/*
Free the allocated memory of one Sommet
s : the sommet to free
*/
void freeSommet(Sommet* s);

/*
Free the allocated memory of one Liste
l : the Liste to free
*/
void freeListe(Liste *l);

/*
Free the allocated memory of an array of Liste
tab : the Liste array
taille : the size of the array
*/
void freeTableau(Liste * tab,int taille);


#endif