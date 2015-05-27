#include <stdio.h>
#include <stdlib.h>
#include "floyd.h"
#include "array.h"

void floyd(arrayT Array, int range){
	int *isUsed;
	int i;

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
		}
		Array->values[im++] = r;
		isUsed[r] = 1;
	}
}