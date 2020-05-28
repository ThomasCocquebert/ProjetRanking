#include "stdio.h"
#include "stdlib.h"
#include "time.h"
#include "../lib/structure.h"
#include "../lib/lecture.h"
#include "../lib/vector.h"
#include "../lib/calcul.h"
#include "../lib/alteration.h"

int main(int argc, char** argv) {

	// ##################################################
	//Setup des variables et ouverture du fichier

	time_t tempsInit = clock();
	srand(time(0));
	if (argc == 1) {
		printf("\033[1;31m");
		printf("Veuillez spécifier un graphe à ouvrir\n");
		printf("\033[0m");
		exit(1);
	} else if (argc > 3) {
		printf("\033[1;31m");
		printf("Trop d'arguments\n");
		printf("\033[0m");
		exit(1);
	}
	double temps = 0.0;
	double ecart = 0.0;
	int percentage = 15;
	if(argv[2] != NULL){
		percentage = atoi(argv[2]);
	}
	printf("Pourcentage = %d\n", percentage);
	FILE* fichier = NULL;
	fichier = fopen(argv[1], "r+");
	if (fichier == NULL) {
		printf("\033[1;31m");
		printf("Impossible d'ouvrir le graphe\n");
		printf("\033[0m");
		exit(1);
	}

	// ##################################################

	// ##################################################
	// Lecture du fichier

	time_t tempsInitTask = clock();
	printf("Chargement du graphe\n");
	int NombreArcs = NBarcs(fichier);
	int NombreSommets = NBsommets(fichier);
	printf("Graphe : %s\n", argv[1]);
	printf("Nb Arc : %d\n", NombreArcs);
	printf("Nb Sommets : %d\n", NombreSommets);
	Liste* tab = LectureFichier(fichier, NombreSommets);
	printf("Fin du chargement\n");
	time_t tempsFinTask = clock();
	temps = (float)(tempsFinTask-tempsInitTask)/CLOCKS_PER_SEC;
	printf("Temps de chargement : %lf\n\n", temps);

	// ##################################################

	// ##################################################
	// Première itération de PageRank

	tempsInitTask = clock();
	printf("Calcul du 1er PageRank\n");
	VEC* x = malloc(sizeof(VEC));
	if(x == NULL) {
		printf("\033[1;31m");
		printf("Allocation du vecteur x échouée\n");
		printf("\033[0m");
		freeTableau(tab, NombreSommets);
		exit(1);
	}
	if(!initVEC(x, NombreSommets)) {
		printf("\033[1;31m");
		printf("Initialisation du vecteur x échouée");
		printf("\033[0m");
		freeTableau(tab, NombreSommets);
		free(x);
		exit(1);
	}
	x = Convergence(tab, x, NombreSommets);
	if(x == NULL) {
		printf("\033[1;31m");
		printf("La convergence n'a pas abouti\n");
		printf("\033[0m");
		freeTableau(tab, NombreSommets);
		exit(1);
	}
	printf("Fin du 1er PageRank\n");
	tempsFinTask = clock();
	temps = (float)(tempsFinTask-tempsInitTask)/CLOCKS_PER_SEC;
	printf("Temps du 1er PageRank : %lf\n\n", temps);

	// ##################################################

	// ##################################################
	// Modification Graphe

	tempsInitTask = clock();
	printf("Début des modifications du graphe\n");
	int nbDelSommets = delColumn(tab, NombreSommets, percentage);
	printf("Nombre de sommets supprimés : %d\n", nbDelSommets);
	int newSommets = NombreSommets -nbDelSommets;
	printf("Nouveau nombre de sommets %d\n", newSommets);
	printf("Fin des modifications du graphe\n");
	tempsFinTask = clock();
	temps = (float)(tempsFinTask-tempsInitTask)/CLOCKS_PER_SEC;
	printf("Temps de modification du graphe : %lf\n\n", temps);
	
	

	// ##################################################

	// ##################################################
	// Calcul du second PageRank

	tempsInitTask = clock();
	printf("Calcul du 2ème PageRank\n");
	VEC* x2 = malloc(sizeof(VEC));
	if(x2 == NULL) {
		printf("\033[1;31m");
		printf("Allocation du vecteur x2 échouée\n");
		printf("\033[0m");
		freeMemVEC(x);
		freeTableau(tab, NombreSommets);
		exit(1);
	}
	if(!initVEC(x2, newSommets)) {
		printf("\033[1;31m");
		printf("Initialisation du vecteur x2 échouée");
		printf("\033[0m");
		freeTableau(tab, NombreSommets);
		freeMemVEC(x);
		free(x2);
		exit(1);
	}
	x2 = Convergence(tab, x2, newSommets);
	if(x2 == NULL) {
		printf("\033[1;31m");
		printf("La convergence n'a pas abouti\n");
		printf("\033[0m");
		freeMemVEC(x);
		freeTableau(tab, NombreSommets);
		exit(1);
	}
	printf("Fin du 2ème PageRank\n");
	tempsFinTask = clock();
	temps = (float)(tempsFinTask-tempsInitTask)/CLOCKS_PER_SEC;
	printf("Temps du 2ème PageRank : %lf\n\n", temps);
	ecart = temps;
	// ##################################################

	// ##################################################
	// PageRank modifié

	tempsInitTask = clock();
	printf("Calcul du PageRank modifié\n");
	VEC* xNorm = malloc(sizeof(VEC));
	if(xNorm == NULL) {
		printf("\033[1;31m");
		printf("Allocation du vecteur xNorm échouée\n");
		printf("\033[0m");
		freeMemVEC(x);
		freeMemVEC(x2);
		freeTableau(tab, NombreSommets);
		exit(1);
	}
	if(!initVECNull(xNorm, newSommets)) {
		printf("\033[1;31m");
		printf("Initialisation du vecteur xNorm échouée\n");
		printf("\033[0m");
		freeMemVEC(x);
		freeMemVEC(x2);
		free(xNorm);
		freeTableau(tab, NombreSommets);
	}
	NewVector(xNorm, x, tab);
	Normalisation(xNorm);
	xNorm = Convergence(tab, xNorm, newSommets);
	if(xNorm == NULL) {
		printf("\033[1;31m");
		printf("La convergence n'a pas abouti\n");
		printf("\033[0m");
		freeMemVEC(x);
		freeMemVEC(x2);
		freeTableau(tab, NombreSommets);
		exit(1);
	}
	printf("Fin du PageRank modifié\n");
	tempsFinTask = clock();
	temps = (float)(tempsFinTask-tempsInitTask)/CLOCKS_PER_SEC;
	printf("Temps du PageRank modifié : %lf\n\n", temps);
	ecart = ecart - temps;
	if(ecart < 0){
		ecart = ecart * -1;
	}
	printf("Ecart du temps d'execution : %lf\n", ecart);
	// ##################################################

	// ##################################################
	// Désallocation mémoire

	tempsInitTask = clock();
	printf("Début de la désallocation mémoire\n");
	freeTableau(tab, NombreSommets);
	freeMemVEC(x);
	freeMemVEC(x2);
	printf("Fin de la désallocation mémoire\n");
	tempsFinTask = clock();
	temps = (float)(tempsFinTask-tempsInitTask)/CLOCKS_PER_SEC;
	printf("Temps de désallocation mémoire : %lf\n", temps);

	// ##################################################

	// ##################################################
	// Fin du programme

	time_t tempsFin = clock();
	temps = (float)(tempsFin-tempsInit)/CLOCKS_PER_SEC;
	printf("Durée totale d'exécution : %lf\n", temps);
	exit(0);

	// ##################################################
}
