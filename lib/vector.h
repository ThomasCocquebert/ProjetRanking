#ifndef VECTOR_H
#define VECTOR_H
#define DELTA 1e-6

/*
Structure of vector
size : the size of the vector
array : the array representing the values of the vector
*/
struct vector
{
	int size;
	double* array;
}; typedef struct vector VEC;

/*
Initialize the vector of size int size with 0 values for each element
vector : the vector to initiliazed
size : the size of the vector to initialized
Return 1 if the allocation is successful or 0 if not
*/
int initVECNull(VEC* vector, int size);

/*
Initialize the vector of size int size at 1/size
vector : the vector to initiliazed
size : the size of the vector to initialized
Return 1 if the allocation is successful or 0 if not
*/
int initVEC(VEC* vector, int size);

/*
Initialize the vector of size int size at 1
vector : the vector to initiliazed
size : the size of the vector to initialized
Return 1 if the allocation is successful or 0 if not
*/
int initVECe(VEC* vector, int size);

/*
Print the vector with its size and its value
vector : the vector to print
Return 1 if the function end properly, 0 if not
*/
int printVEC(VEC* vector);

/*
Free the allocated memory for the vector and free the vector itself at the end
vector : the vector to free
*/
void freeMemVEC(VEC* vector);

/*
Make v2 - v1 and return this in a VEC*
v1 : the first vector (represent x^n)
v2 : the second vector (represent x^n+1)
Return the address of the VEC containing v1 - v2 or NULL if v1 and v2 have diffeent size
*/
VEC* minusVector(VEC* v1, VEC* v2);

/*
Compare 2 vectors and check if the difference between each element is < DELTA
v1 : the first vector (represent x^n)
v2 : the second vector (represent x^n+1)
Return 1 if true, 0 if false, -1 if an error occured
*/
int compVector(VEC* v1, VEC* v2);

/*
Multiply a vector by a double
v : the vector to multiply
mult : the double for the multiply
Return 1 if the functon end properly or 0 if an error occured
*/
int VECByDouble(VEC* v, double mult);

/*
Add a double to a vector
v : the vector for the addition
add : the double to add
Return 1 if the functon end properly or 0 if an error occured
*/
int VECAddDouble(VEC* v, double add);

/*
 Add two vector
 v : the first vector
 v2 : the second vector
 Return 1 if the functon end properly or 0 if an error occured
 */
int VECAddVector(VEC* v, VEC* v2);

/*
Multiply one row vector by one columne vector
v1 : the row vector
v2 : the columne vector
Return the multiplication of v1 by v2
*/
double VxVt(VEC *v1, VEC *v2);

/*
Get the new vector for the loop
Vnew : new vector
Vold : old Vector
tab : Graph
Return 1 if the functon end properly or 0 if an error occured
*/
int NewVector(VEC* Vnew, VEC* Vold, Liste* tab);

/*
Get ||v||1
v : vector
Return the norm1 of v
*/
double Norme1(VEC* v);

/*
Normalization of v
v : vector
Return the adress of the normalized vector of NULL if error
*/
VEC* Normalisation(VEC* v);

/*
Copy of a vector
v : vector
Return 1 if the fucntion end properly or 0 if an error occured
*/
int CopyVector(VEC* v,VEC* v2);
#endif
