#include <time.h>
#include "analyzer.h"
#include "selectionAlg.h"
#include "floyd.h"
#include "array.h"

static double GetCurrentCPUTime(void);

void timer(void){
	double start;
	int i, result;

	arrayT Array, origArray;
	int kElement;

	origArray = newArrayT();
	Array = newArrayT();
	//floyd(origArray, RANGE);
	sequencer(origArray, RANGE);

	kElement = 1 + rand() % (ARRAYSIZE);

	printf("Array[");
	for (i = 0; i < ARRAYSIZE; i++){
		printf("%d, ", origArray->values[i]);
	}
	printf("]\n");

	/* quickselect with Lomuto-partition */
	start = GetCurrentCPUTime();
	for (i = 0; i < NUMBEROFREPS; i++) {
		restoreArray(Array, origArray);
		result = quickSelect(Array, kElement, LOMUTO);
	}

	printf("Time to run quickSelect with LOMUTO-partition on a %d elements large array, finding the k:th smallest element:\n %g usecs\n\n", ARRAYSIZE,
		1000.0*(GetCurrentCPUTime() - start) / (NUMBEROFREPS));
	printf("The *%d* smallest element was %d\n\n", kElement, result);
	
	/* quickselect with Hoare-partition */
	start = GetCurrentCPUTime();
	for (i = 0; i < NUMBEROFREPS; i++) {
		restoreArray(Array, origArray);
		result = quickSelect(Array, kElement, HOARE);
	}
	printf("Time to run quickSelect with HOARE-partition on a %d elements large array, finding the k:th smallest element:\n %g usecs\n\n", ARRAYSIZE,
		1000.0*(GetCurrentCPUTime() - start) / (NUMBEROFREPS));
	printf("The *%d* smallest element was %d\n\n", kElement, result);
	
	/* bruteselect */
	start = GetCurrentCPUTime();
	for (i = 0; i < NUMBEROFREPS; i++) {
		restoreArray(Array, origArray);
		result = bruteSelect(Array, kElement);
	}
	printf("Time to run a bruteforce-version Select on a %d elements large array, finding the k:th smallest element:\n %g usecs\n\n", ARRAYSIZE,
		1000.0*(GetCurrentCPUTime() - start) / (NUMBEROFREPS));
	printf("The *%d* smallest element was %d\n\n", kElement, result);
	freeArrayT(Array);
	freeArrayT(origArray);
}

static double GetCurrentCPUTime(){
	return (clock() * 1000.0 / CLOCKS_PER_SEC);
}