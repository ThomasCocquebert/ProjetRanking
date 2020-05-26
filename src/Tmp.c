#include "stdlib.h"
#include "stdio.h"
#include "../lib/vector.h"

double VxVt(vector v1, vector v2){
	double res = 0;
	int i;
	for(i = 0; i < v1.size; i++){		//On parcours les vecteurs en entier
		res = res + (v1[i] * v2[i]);
	}
	printf("Res = %lf\n", res);
	return res;
}

