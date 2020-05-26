#ifndef CALCUL_H
#define CALCUL_H

/*
Compute the F vector for the List tab
tab : the List of Sommet
taille : the size of the vector f
Return the pointer of vector
*/
VEC * computeF(Liste * tab, int taille);

/*
Compute the operation pi multiple by matrix tab
tab : the Liste of Sommet
pi : the vector to multiply
size : the size of vector
Return an address of VEC
*/
VEC* computePiG(Liste* tab, VEC* pi, int size);

/*
Test the convergence of the matrix
tab : the Liste of Sommet
size : the size of the vector pi
Return -1 if error during allocation of vectors, 0 if no convergence, 1 if not
*/
int convergeTest(Liste* tab, int size);

#endif