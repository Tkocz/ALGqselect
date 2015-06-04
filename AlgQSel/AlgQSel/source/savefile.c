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
	fprintf(stats, "Size of Array: %d\n", ARRAYSIZE);

	fprintf(stats, "\nQuickSelect - Lomuto \nLoopCounts: %d\n", counter->lomuto->LoopCounts);
	fprintf(stats, "Recursions: %d\n", counter->lomuto->recursions);
	fprintf(stats, "Time: %g usecs\n", counter->lomuto->timer);

	fprintf(stats, "\nQuickSelect - Hoare's \nLoopCounts: %d\n", counter->hoare->LoopCounts);
	fprintf(stats, "Recursions: %d\n", counter->hoare->recursions);
	fprintf(stats, "Time: %g usecs\n", counter->hoare->timer);

	fprintf(stats, "\nBruteSelect - \nLoopCounts: %d\n", counter->brute->LoopCounts);
	fprintf(stats, "Recursions: %d\n", counter->brute->recursions);
	fprintf(stats, "Time: %g usecs\n", counter->brute->timer);

	fclose(stats);
	printf("\nThe data has been saved to %s\n", filename);
}