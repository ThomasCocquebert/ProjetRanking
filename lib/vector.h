#ifndef VECTOR_H
#define VECTOR_H
#define DELTA 0.0000001

/*
Structure of vector
int size is the number of element in the vector
double* array is the array where element of the vectore are stored
*/
struct vector
{
	int size;
	double* array;
}; typedef struct vector VEC;

/*
Initialize the vector of size int size at 
return 1 if the allocation is successful or 0 if not
*/
int initVECNull(VEC* vector, int size);

/*
Initialize the vector of size int size at 1/size
return 1 if the allocation is successful or 0 if not
*/
int initVEC(VEC* vector, int size);

/*
Print the vector with its size and its value
*/
void printVEC(VEC* vector);

/*
Free the allocated memory for the vector
Free the vector itself at the end
*/
void freeMemVEC(VEC* vector);

/*
Make v2 - v1 and return this in a VEC*
return NULL if v1 and v2 have diffeent size
*/
VEC* minusVector(VEC* v1, VEC* v2);

/*
Compare 2 vectors and check if the difference between each element is < DELTA
return 1 if true, 0 if false, -1 if the two vectors has a different size
*/
int compVector(VEC* v1, VEC* v2);

#endif