#include "array.h"
#include <stdlib.h>

arrayT newArrayT(int n) {
	arrayT array = malloc(sizeof(arrayT));

	array->values = malloc(sizeof(int)*n);
	array->nValues = n;
	return array;
}
void swap(arrayT Array, int x, int y){
	int tmp;
	tmp = Array->values[x];
	Array->values[x] = Array->values[y];
	Array->values[y] = tmp;
}