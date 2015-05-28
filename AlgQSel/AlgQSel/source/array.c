#include "array.h"
#include <stdlib.h>

arrayT newArrayT(int n) {
	arrayT array = malloc(sizeof(arrayT));

	array->values = malloc(sizeof(int)*n);
	array->nValues = n;
	array->lIndex = 0;
	array->rIndex = n - 1;
	return array;
}
void swap(arrayT Array, int x, int y){
	
	if (x == y)
		return;
	int tmp;
	tmp = Array->values[x];
	Array->values[x] = Array->values[y];
	Array->values[y] = tmp;
}
void freeArrayT(arrayT Array){

	free(Array->values);
	//free(Array);
}