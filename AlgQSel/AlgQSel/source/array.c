#include "array.h"
#include <stdlib.h>
#include "inc/genlib.h"

arrayT newArrayT(int n) {
	arrayT array = malloc(sizeof(arrayT));

	array->values = malloc(sizeof(int)*n);
	array->nValues = n;
	return array;
}