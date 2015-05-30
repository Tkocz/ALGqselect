#include "array.h"
#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include "analyzer.h"

arrayT newArrayT(void) {
	arrayT array = calloc(ARRAYSIZE, sizeof(int));

	array->values = calloc(ARRAYSIZE, sizeof(int));
	array->nValues = ARRAYSIZE;
	array->lIndex = 0;
	array->rIndex = ARRAYSIZE - 1;
	return array;
}
void swap(arrayT Array, int x, int y){
	if (x >= Array->nValues || x >= Array->nValues)
		printf("Index overload");
	if (x == y)
		return;
	int tmp;
	tmp = Array->values[x];
	Array->values[x] = Array->values[y];
	Array->values[y] = tmp;
}

void restoreArray(arrayT Array, arrayT origArray){
	memcpy(Array->values, origArray->values, sizeof(int)*ARRAYSIZE);
	Array->nValues = origArray->nValues;
	Array->lIndex = origArray->lIndex;
	Array->rIndex = origArray->rIndex;
}

void freeArrayT(arrayT Array){

	free(Array->values);
	Array->nValues = NULL;
	Array->lIndex = NULL;
	Array->rIndex = NULL;
	free(Array);
}