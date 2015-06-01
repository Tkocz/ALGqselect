#include <time.h>
#include "analyzer.h"
#include "selectionAlg.h"
#include "sequencer.h"
#include "array.h"
#include <string.h>
#include <stdio.h>
#include <stdlib.h>

typedef char *string;

typedef struct algTrackT {
	int timer;
	int recursions;
	int LoopCounts;
	int memUse;
} *algTrackT;

typedef struct counterT {
	int			numReps;
	algTrackT	lomuto;
	algTrackT	hoare;
	algTrackT	brute;
} *counterT;

static counterT counter;

static double GetCurrentCPUTime(void);
counterT initCounter(void);
void freeCounter(counterT counter);
void save(counterT counter);

void performance(void){
	double start;
	int i, result;


	arrayT Array, origArray;
	int kElement;

	origArray = newArrayT();
	Array = newArrayT();
	sequencer(origArray, RANGE);

	counter = initCounter();

	printArray(origArray);

	/* quickselect with Lomuto-partition */
	start = GetCurrentCPUTime();
	for (i = 0; i < NUMBEROFREPS; i++) {
		restoreArray(Array, origArray);
		kElement = rand() % (ARRAYSIZE);
		result = quickSelect(Array, kElement, LOMUTO);
	}
	printf("Average time to run quickSelect with LOMUTO-partition on a %d elements large array,\n finding the k:th smallest element:\n %g usecs\n\n", 
		ARRAYSIZE, 1000.0*(GetCurrentCPUTime() - start) / (NUMBEROFREPS));

	
	/* quickselect with Hoare-partition */
	start = GetCurrentCPUTime();
	for (i = 0; i < NUMBEROFREPS; i++) {
		restoreArray(Array, origArray);
		kElement = rand() % (ARRAYSIZE);
		result = quickSelect(Array, kElement, HOARE);
	}
	printf("Average time to run quickSelect with HOARE-partition on a %d elements large array,\n finding the k:th smallest element:\n %g usecs\n\n", 
		ARRAYSIZE, 1000.0*(GetCurrentCPUTime() - start) / (NUMBEROFREPS));
	
	/* bruteselect */
	start = GetCurrentCPUTime();
	for (i = 0; i < NUMBEROFREPS; i++) {
		restoreArray(Array, origArray);
		kElement = rand() % (ARRAYSIZE);
		counter->brute->memUse = bruteSelect(Array, kElement);
	}
	printf("Average time to run a bruteforce-version Select on a %d elements large array,\n finding the k:th smallest element:\n %g usecs\n\n", 
		ARRAYSIZE, 1000.0*(GetCurrentCPUTime() - start) / (NUMBEROFREPS));

	save(counter);

	freeArrayT(Array);
	freeArrayT(origArray);
	freeCounter(counter);
}

static double GetCurrentCPUTime(){
	return (clock() * 1000.0 / CLOCKS_PER_SEC);
}

counterT initCounter(void){

	counterT counter = calloc(4, sizeof(counterT));
	algTrackT brute = calloc(4, sizeof(algTrackT));
	algTrackT lomuto = calloc(4, sizeof(algTrackT));
	algTrackT hoare = calloc(4, sizeof(algTrackT));

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

void save(counterT counter) {
	string filename = "stats.txt";
	FILE* stats = fopen(filename, "w");
	
	if (stats == NULL) {
		printf("Could not open file %s for writing.", filename);
	}
	fprintf(stats, "Number of repetitions; %d\n\n", counter->numReps);

		fprintf(stats, "counter->lomuto->LoopCounts: %d\n", counter->hoare->LoopCounts);
		fprintf(stats, "counter->lomuto->recursions: %d\n", counter->hoare->recursions);
		fprintf(stats, "counter->lomuto->timer: %d\n", counter->hoare->timer);
		fprintf(stats, " counter->lomuto->memUse: %d\n\n", counter->hoare->memUse);

		fprintf(stats, "counter->hoare->LoopCounts: %d\n", counter->hoare->LoopCounts);
		fprintf(stats, "counter->hoare->recursions: %d\n", counter->hoare->recursions);
		fprintf(stats, "counter->hoare->timer: %d\n", counter->hoare->timer);
		fprintf(stats, " counter->hoare->memUse: %d\n\n", counter->hoare->memUse);

		fprintf(stats, "counter->brute->LoopCounts: %d\n", counter->hoare->LoopCounts);
		fprintf(stats, "counter->brute->recursions: %d\n", counter->hoare->recursions);
		fprintf(stats, "counter->brute->timer: %d\n", counter->hoare->timer);
		fprintf(stats, " counter->brute->memUse: %d\n\n", counter->hoare->memUse);

	fclose(stats);
}
void sendData(nåntingnånting)