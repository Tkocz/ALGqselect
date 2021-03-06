/*
* File: array.h
* --------------
* Interface for creating structed arrays containing both the array and a value
* representening the number of elements. Also a simple swap-function.
*
* Martin Bergqvist, ASYAR14
* Senast modifierad: 27/5 - 2015
*/

#ifndef _array_h_
#define _array_h_

#include <stdlib.h>

typedef struct arrayT {
	int *values;
	int lIndex;
	int rIndex;
	int nValues;
} *arrayT;

arrayT newArrayT(int size);

void swap(arrayT Array, int x, int y);

void restoreArray(arrayT Array, arrayT origArray);

void freeArrayT(arrayT Array);

void printArray(arrayT Array);

#endif