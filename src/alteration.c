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

void delColumn(Liste* tab, int size) {
	int j = 0;
	for(int i = 0; i < size; i++) {
		if(testDel()) {
			j++;
			freeListe(&tab[i]);
			tab[i].first = NULL;
			tab[i].exist = 0;
		}
	}
	printf("%d deleted columne\n", j);
}