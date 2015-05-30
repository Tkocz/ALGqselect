#include <stdio.h>
#include <stdlib.h>
#include "sequencer.h"
#include "array.h"

void sequencer(arrayT Array, int range){
	int *isUsed;
	int i, counter;
	counter = 0;
	if (Array->nValues > range)		//Errorhandling for faulty input
		range = Array->nValues;

	isUsed = calloc(range,sizeof(int));

	int in, im;

	im = 0;

	for (in = range - Array->nValues ; in < range && im < Array->nValues; ++in) {
		int r = rand() % range; //Generate a random number r

		while (isUsed[r])	//If r is used
		{
			r = rand() % range;
			counter++;
		}
		Array->values[im++] = r;
		isUsed[r] = 1;
		counter++;
	}
	free(isUsed);
}

void floyd(arrayT Array, int range){
	int i, t, pos;
	pos = 0;

	if (Array->nValues > range)		//Errorhandling for faulty input
		range = Array->nValues;

	for (i = (range - Array->nValues + 1); i <= range; i++){
		
		t = rand() % (i);

		if (isNotIn(Array, t)){
			Array->values[pos] = t;
		}
		else
			Array->values[pos] = i;
		pos++;
	}
	for (i = Array->nValues-1; i >= 2; i--){
		swap(Array, (rand() % i), i);
		pos++;
	}
	printf("number of loops : %d\n", pos);
}

int isNotIn(arrayT Array, int t){
	int i;
	for (i = 0; i < Array->nValues; i++){
		if (Array->values[i] == t)
			return 0;
	}
	return 1;
}
