#include <time.h>
#include "analyzer.h"
#include "selectionAlg.h"
#include "sequencer.h"
#include "array.h"

typedef struct counterCDT {
	int numReps;
	int *lomuto;
	int *qsortLo;
	int *hoare;
	int *qsortHo;
	int *brute;
	int nReps;
} counterCDT;

static double GetCurrentCPUTime(void);

void timer(void){
	double start;
	int i, result;
	counterADT counter;

	arrayT Array, origArray;
	int kElement;

	origArray = newArrayT();
	Array = newArrayT();
	//floyd(origArray, RANGE);
	sequencer(origArray, RANGE);

	counter = initCounter();
	freeCounter(counter);

	kElement = rand() % (ARRAYSIZE);

	printArray(origArray);

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

counterADT initCounter(void){

		counterADT counter;

		counter = malloc(sizeof(counterCDT));
		counter->numReps = NUMBEROFREPS;
		counter->lomuto = malloc(NUMBEROFREPS*sizeof(int));
		counter->qsortLo = malloc(NUMBEROFREPS*sizeof(int));
		counter->hoare = malloc(NUMBEROFREPS*sizeof(int));
		counter->qsortHo = malloc(NUMBEROFREPS*sizeof(int));
		counter->brute = malloc(NUMBEROFREPS*sizeof(int));
		return counter;
}

void freeCounter(counterADT counter){

	counter->numReps = NULL;
	free(counter->lomuto);
	free(counter->qsortLo);
	free(counter->hoare);
	free(counter->qsortHo);
	free(counter->brute);
	free(counter);
}