#include <time.h>
#include "analyzer.h"
#include "selectionAlg.h"
#include "floyd.h"
#include "array.h"

static double GetCurrentCPUTime(void);

void timer(void){
	double start;
	int i, result;

	arrayT Array;
	int kElement;

	Array = newArrayT(ARRAYSIZE);
	floyd(Array, RANGE);

	kElement = rand() % (ARRAYSIZE + 1);
	//printf("The %d:d smallest element\n", kElement);

	/* quickselect with Hoare-partition */
	start = GetCurrentCPUTime();
		for (i = 0; i < NUMBEROFREPS; i++) {
			result = quickSelect(Array, kElement, HOARE);
		}
	printf("Time to run quickSelect with HOARE-partition on a %d elements large array, finding the k:th smallest element:\n %g usecs\n\n", ARRAYSIZE,
		1000.0*(GetCurrentCPUTime() - start) / (NUMBEROFREPS));
	printf("The *%d* smallest element was %d\n\n", kElement, result);

	/* quickselect with Lomuto-partition */
	start = GetCurrentCPUTime();
	for (i = 0; i < NUMBEROFREPS; i++) {
		result = quickSelect(Array, kElement, LOMUTO);
	}
	printf("Time to run quickSelect with LOMUTO-partition on a %d elements large array, finding the k:th smallest element:\n %g usecs\n\n", ARRAYSIZE,
		1000.0*(GetCurrentCPUTime() - start) / (NUMBEROFREPS));
	printf("The *%d* smallest element was %d\n\n",kElement, result);

	/* bruteselect */
	start = GetCurrentCPUTime();
	for (i = 0; i < NUMBEROFREPS; i++) {
		result = bruteSelect(Array, kElement);
	}
	printf("Time to run a bruteforce-version Select on a %d elements large array, finding the k:th smallest element:\n %g usecs\n\n", ARRAYSIZE,
		1000.0*(GetCurrentCPUTime() - start) / (NUMBEROFREPS));
	printf("The *%d* smallest element was %d\n\n",kElement, result);

	system("pause");

}

static double GetCurrentCPUTime(){
	return (clock() * 1000.0 / CLOCKS_PER_SEC);
}