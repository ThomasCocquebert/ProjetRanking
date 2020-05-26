#ifndef VECTOR_H
#define VECTOR_H
#define DELTA 0.000001

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
Print the vector with its size and its value
vector : the vector to print
*/
void printVEC(VEC* vector);

/*
Free the allocated memory for the vector and free the vector itself at the end
vector : the vector to free
*/
void freeMemVEC(VEC* vector);

/*
Make v2 - v1 and return this in a VEC*
v1 : the first vector (represent x^n)
v2 : the second vector (represent x^n+1)
Return NULL if v1 and v2 have diffeent size
*/
VEC* minusVector(VEC* v1, VEC* v2);

/*
Compare 2 vectors and check if the difference between each element is < DELTA
v1 : the first vector (represent x^n)
v2 : the second vector (represent x^n+1)
Return 1 if true, 0 if false, -1 if the two vectors has a different size
*/
int compVector(VEC* v1, VEC* v2);

#endif