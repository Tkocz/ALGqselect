#ifndef _array_h_
#define _array_h_

#include <stdlib.h>

typedef struct arrayT {
	int *values;
	int nValues;
} *arrayT;

arrayT newArrayT(int n);

#endif