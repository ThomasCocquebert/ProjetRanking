#ifndef ALTERATION_H
#define ALTERATION_H

/*
Generated a random number between 0 and 99
Return the generated number
*/
int genNumber();

/*
Test if the Sommet or the edge should be deleted with probability  = 1%
Call the function genNumber and test if the generated number is equal 0
Return 1 if true, 0 if false
*/
int testDel();

/*
Delete Sommet of a Liste and set its value exist at 0
tab : the array of List representing the matrix
size : the size of the tab
*/
void delColumn(Liste* tab, int size);
#endif