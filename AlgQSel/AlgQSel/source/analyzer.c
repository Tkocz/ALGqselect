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

	origArray = newArrayT(ARRAYSIZE);
	Array = newArrayT(ARRAYSIZE);
	floyd(origArray, RANGE);

	//kElement = 1+rand() % (ARRAYSIZE);
	kElement = 10;

	printf("Array[");
	for (i = 0; i < ARRAYSIZE; i++){
		printf("%d, ", origArray->values[i]);
	}
	printf("]\n");

	/* quickselect with Hoare-partition */
	start = GetCurrentCPUTime();
		//for (i = 0; i < NUMBEROFREPS; i++) {
			memcpy(Array->values, origArray->values, sizeof(int)*ARRAYSIZE);
			Array->nValues = origArray->nValues;
			result = quickSelect(Array, kElement, HOARE);
		//}
	printf("Time to run quickSelect with HOARE-partition on a %d elements large array, finding the k:th smallest element:\n %g usecs\n\n", ARRAYSIZE,
		1000.0*(GetCurrentCPUTime() - start) / (NUMBEROFREPS));
	printf("The *%d* smallest element was %d\n\n", kElement, result);
	
	/* quickselect with Lomuto-partition 
	start = GetCurrentCPUTime();
	//for (i = 0; i < NUMBEROFREPS; i++) {
		memcpy(Array->values, origArray->values, sizeof(int)*ARRAYSIZE);
		Array->nValues = origArray->nValues;
		Array->lIndex = origArray->lIndex;
		Array->rIndex = origArray->rIndex;
		result = quickSelect(Array, kElement, LOMUTO);
	//}
	printf("Time to run quickSelect with LOMUTO-partition on a %d elements large array, finding the k:th smallest element:\n %g usecs\n\n", ARRAYSIZE,
		1000.0*(GetCurrentCPUTime() - start) / (NUMBEROFREPS));
	printf("The *%d* smallest element was %d\n\n",kElement, result);
	*/
	/* bruteselect 
	start = GetCurrentCPUTime();
	for (i = 0; i < NUMBEROFREPS; i++) {
		memcpy(Array->values, origArray->values, sizeof(int)*ARRAYSIZE);
		Array->nValues = origArray->nValues;
		result = bruteSelect(Array, kElement);
	}
	printf("Time to run a bruteforce-version Select on a %d elements large array, finding the k:th smallest element:\n %g usecs\n\n", ARRAYSIZE,
		1000.0*(GetCurrentCPUTime() - start) / (NUMBEROFREPS));
	printf("The *%d* smallest element was %d\n\n",kElement, result);
	*/
	system("pause");

}

static double GetCurrentCPUTime(){
	return (clock() * 1000.0 / CLOCKS_PER_SEC);
}