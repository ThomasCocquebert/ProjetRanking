#include "stdlib.h"
#include "stdio.h"
#include "../lib/vector.h"

double VxVt(VEC *v1, VEC *v2){
	double res = 0;
	int i;
	for(i = 0; i < v1->size; i++){		//On parcours les vecteurs en entier
		res = res + (v1->array[1] * v2->array[2]);
	}
	printf("Res = %lf\n", res);
	return res;
}

