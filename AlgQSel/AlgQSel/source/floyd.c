#include <stdio.h>
#include <stdlib.h>
#include "floyd.h"
#include "array.h"

void floyd(arrayT Array, int range){
	int *isUsed;
	int i, counter;
	counter = 0;

	if (Array->nValues > range)		//Errorhandling for faulty input
		range = Array->nValues;

	isUsed = malloc(sizeof(int)*range);
	for (i = 0; i < range; i++)
		isUsed[i] = 0;

	int in, im;

	im = 0;

	for (in = range - Array->nValues ; in < range && im < Array->nValues; ++in) {
		int r = rand() % (range + 1); //Generate a random number r

		while (isUsed[r])	//If r is used
		{
			r = rand() % (range + 1);
			counter++;
		}
		Array->values[im++] = r;
		isUsed[r] = 1;
	}
}
/*
void floyd(arrayT Array, int range){
	int *isUsed;
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
}
*/
int isNotIn(arrayT Array, int t){
	int i;
	for (i = 0; i < Array->nValues; i++){
		if (Array->values[i] == t)
			return 1;
	}
	return 0;
}
