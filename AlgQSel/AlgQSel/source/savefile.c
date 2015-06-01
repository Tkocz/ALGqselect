#include "savefile.h"
#include <string.h>
#include <stdio.h>
#include <stdlib.h>

void save(counterT counter) {
	string filename = strdup("stats");
	char arraySize[100] = { 0 };
	sprintf(arraySize, "%d", ARRAYSIZE);
	strcat(filename, arraySize);
	strcat(filename, ".txt");
	FILE* stats = fopen(filename, "w");

	if (stats == NULL) {
		printf("Could not open file %s for writing.", filename);
	}
	fprintf(stats, "Size of Array: %d", ARRAYSIZE);
	fprintf(stats, "	Number of repetitions: %d\n\n", counter->numReps);

	fprintf(stats, "counter->lomuto->LoopCounts: %d\n", counter->lomuto->LoopCounts);
	fprintf(stats, "counter->lomuto->recursions: %d\n", counter->lomuto->recursions);
	fprintf(stats, "counter->lomuto->timer: %g\n", counter->lomuto->timer);

	fprintf(stats, "counter->hoare->LoopCounts: %d\n", counter->hoare->LoopCounts);
	fprintf(stats, "counter->hoare->recursions: %d\n", counter->hoare->recursions);
	fprintf(stats, "counter->hoare->timer: %g\n", counter->hoare->timer);

	fprintf(stats, "counter->brute->LoopCounts: %d\n", counter->brute->LoopCounts);
	fprintf(stats, "counter->brute->recursions: %d\n", counter->brute->recursions);
	fprintf(stats, "counter->brute->timer: %g\n", counter->brute->timer);

	fclose(stats);
}