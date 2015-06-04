#include <time.h>
#include "analyzer.h"
#include "selectionAlg.h"
#include "sequencer.h"
#include "array.h"
#include <string.h>
#include <stdio.h>
#include <stdlib.h>

static double GetCurrentCPUTime(void);
void save(counterT counter);

void performance(void){
	double start;
	int i, result;


	arrayT Array, origArray;
	int *kElement;
	kElement = malloc(NUMBEROFREPS*sizeof(int));

	origArray = newArrayT(ARRAYSIZE);
	Array = newArrayT(ARRAYSIZE);
	sequencer(origArray, RANGE);
	counter = initCounter();

	for (i = 0; i < NUMBEROFREPS; i++) {
		kElement[i] = 1 + rand() % (ARRAYSIZE-1);
	}

	printArray(origArray);

	/* quickselect with Lomuto-partition */
	start = GetCurrentCPUTime();
	for (i = 0; i < NUMBEROFREPS; i++) {
		restoreArray(Array, origArray);
		result = quickSelect(Array, kElement[i], LOMUTO, counter);
	}
	counter->lomuto->timer = 1000.0*(GetCurrentCPUTime() - start) / (NUMBEROFREPS);
	printf("Average time to run quickSelect with LOMUTO-partition on a %d elements large array,\n finding the k:th smallest element:\n %g usecs\n\n",
		ARRAYSIZE, counter->lomuto->timer);

	/* quickselect with Hoare-partition */
	start = GetCurrentCPUTime();
	for (i = 0; i < NUMBEROFREPS; i++) {
		restoreArray(Array, origArray);
		result = quickSelect(Array, kElement[i], HOARE, counter);
	}
	counter->hoare->timer = 1000.0*(GetCurrentCPUTime() - start) / (NUMBEROFREPS);
	printf("Average time to run quickSelect with HOARE-partition on a %d elements large array,\n finding the k:th smallest element:\n %g usecs\n\n",
		ARRAYSIZE, counter->hoare->timer);

	/* bruteselect */
	start = GetCurrentCPUTime();
	for (i = 0; i < NUMBEROFREPS; i++) {
		restoreArray(Array, origArray);
		result = bruteSelect(Array, kElement[i], counter);
	}
	counter->brute->timer = 1000.0*(GetCurrentCPUTime() - start) / (NUMBEROFREPS);
	printf("Average time to run a bruteforce-version Select on a %d elements large array,\n finding the k:th smallest element:\n %g usecs\n\n",
		ARRAYSIZE, counter->brute->timer);

	counter->brute->LoopCounts /= NUMBEROFREPS;
	counter->hoare->LoopCounts /= NUMBEROFREPS;
	counter->lomuto->LoopCounts /= NUMBEROFREPS;
	counter->hoare->recursions /= NUMBEROFREPS;
	counter->lomuto->recursions /= NUMBEROFREPS;
	save(counter);

	freeArrayT(Array);
	freeArrayT(origArray);
	freeCounter(counter);
	system("pause");
}

static double GetCurrentCPUTime(){
	return (clock() * 1000.0 / CLOCKS_PER_SEC);
}

counterT initCounter(void){

	counterT counter = calloc(4, sizeof(counterT));
	algTrackT brute = calloc(4, sizeof(double));
	algTrackT lomuto = calloc(4, sizeof(double));
	algTrackT hoare = calloc(4, sizeof(double));

	counter->brute = brute;
	counter->lomuto = lomuto;
	counter->hoare = hoare;

	counter->numReps = NUMBEROFREPS;

	return counter;
}

void freeCounter(counterT counter){

	free(counter->brute);
	free(counter->lomuto);
	free(counter->hoare);
	free(counter);
}