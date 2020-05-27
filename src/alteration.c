#include "stdlib.h"
#include "stdio.h"
#include "time.h"
#include "../lib/structure.h"
#include "../lib/alteration.h"

int genNumber() {
	return (rand()%(100));
}

int testDel() {
	if(genNumber() == 0) {
		return 1;
	}
	return 0;
}

int delColumn(Liste* tab, int size) {
	if(tab == NULL) {
		printf("\033[1;31m");
		printf("tab uninitialized\n");
		printf("Error in delColumn\n");
		printf("\033[0m");
		return -1;
	}
	int j = 0;
	for(int i = 0; i < size; i++) {
		if(testDel()) {
			j++;
			freeListe(&tab[i]);
			tab[i].first = NULL;
			tab[i].exist = 0;
		}
	}
	return j;
}
