#ifndef CALCUL_H
#define CALCUL_H
#ifndef STRUCTURE_H
	# include "structure.h"
#endif
#ifndef VECTOR_H
	# include "vector.h"
#endif

/*
Compute the F vector for the List tab
tab : the List of Sommet
taille : the size of the vector f
Return the pointer of vector or NULL if an error occured during the function
*/
VEC * computeF(Liste * tab, int taille);

/*
Compute the operation pi multiple by matrix tab
tab : the Liste of Sommet
pi : the vector to multiply
size : the size of vector
Return an address of VEC or NULL an error occured
*/
VEC* computePiG(Liste* tab, VEC* pi, int size);

/*
Compute the PageRank formula
tab : the Liste of Sommet
x : the vector
size : the size of the vector
Return the address of the new vector x or NULL if an error occured
*/
VEC* PageRank(Liste* tab, VEC* x, int size);

/*
Test if the matrix converge in 1000 iterations or less
tab : the Liste of Sommet
x : the vector
taille : the size of the vector
Return the adress of the vector during the convergenece or NULL if error
*/
VEC* Convergence(Liste* tab, VEC* x, int taille);

#endif