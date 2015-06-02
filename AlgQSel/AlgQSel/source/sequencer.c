#include <stdio.h>
#include <stdlib.h>
#include "sequencer.h"
#include "array.h"

//ALGORITHM floyd(ArrayT, range)
// for J : = N - M + 1 to N do
// T : = RandInt(1, J)
//	 if T is not in S then
//	 	insert T in S
//	 else
//	 insert J in S
// 
static void floyd(arrayT Array, int range);

//ALGORITHM randomizer(ArrayT, range)
//for (I : = N - M; to N do
//	R : = RandInt(1, RANGE)
//
//	while R is used
//		R : = RandInt(1, RANGE)
static void randomizer(arrayT Array, int range);

static int isNotIn(arrayT Array, int t);


void sequencer(arrayT Array, int range){
	if (Array->nValues * 2 > range)
		randomizer(Array, range);
	else
		floyd(Array, range);
}

void randomizer(arrayT Array, int range){
	if (Array->nValues > range)		//Errorhandling for faulty input
		range = Array->nValues;

	int *isUsed;
	int i, r;

	isUsed = calloc(range,sizeof(int));

	for (i = 0 ; i < Array->nValues; ++i) {
		r = rand() % range; //Generate a random number r

		while (isUsed[r])	//If r is used
		{
			r = rand() % range;
		}
		Array->values[i] = r;
		isUsed[r] = 1;
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
	}
}

int isNotIn(arrayT Array, int t){
	int i;
	for (i = 0; i < Array->nValues; i++){
		if (Array->values[i] == t)
			return 0;
	}
	return 1;
}
