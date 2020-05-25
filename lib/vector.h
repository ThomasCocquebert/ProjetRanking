#ifndef VECTOR_H
#define VECTOR_H

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

#endif