#ifndef ALTERATION_H
#define ALTERATION_H
#ifndef STRUCTURE_H
	# include "structure.h"
#endif

/*
Generated a random number between 0 and 99
Return the generated number
*/
int genNumber();

/*
Test if the Sommet or the edge should be deleted with probability  = 1%
Call the function genNumber and test if the generated number is equal 0
percentage : the % of delete
Return 1 if true, 0 if false
*/
int testDel(int percentage);

/*
Delete Sommet of a Liste and set its value exist at 0
tab : the array of List representing the matrix
size : the size of the tab
percentage : percentage of delete
Return the number of deleted column or -1 if tab is uninitialized
*/
int delColumn(Liste* tab, int size, int percentage);


/*
Delete all element Sommet link to a specific line of each column.
* tab : the array of List representing the matrix
* ligne : the line number
* taille : size of the matrix
 */
int delLigne(Liste* tab, int ligne, int taille);

/*
UNUSED FUNCTION
*/
int delLigne2(Liste* tab, int ligne, int taille);

/*
UNUSED FUNCTION
*/
void deleteSommet(Liste* liste, int ligne);

/*
 * Delete arc from a a Array liste* with a percentage
 * tab: the array of List representing the matrix.
 * size : the size of the tab
 * perc : percentage of deleted arcs
 * RETURN the number of arcs deleted
*/
int delArc(Liste* tab, int size,int perc);

/*
 * Delete arc from liste* with a percentage
 * liste : Liste* representif a column
 * perc : percentage of deleted arcs
 * RETURN the number of arcs deleted
*/
int delArcListe(Liste* liste, int perc);

/*
 * Delete arc and column in the matrix
 * arc : number of arc deleted is stored in this int*
 * tab: array of liste* representing the matrix
 * pColumn : percentage of deleted column
 * pArc : percentage of deleted ard
 * RETURN the number of column deleted
*/
int delColumnArc(int* arc,Liste* tab, int size, int pColumn, int pArc);
#endif
