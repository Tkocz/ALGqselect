#include "playground.h"
#include "array.h"
#include "floyd.h"
#include <stdio.h>
#include "selectionAlg.h"
#include "analyzer.h"

void playGround(void){

	arrayT Array;
	int i, kElement, kValue;
	Array = newArrayT(ARRAYSIZE);
	floyd(Array, RANGE);
	printf("Array[");
	for (i = 0; i < ARRAYSIZE; i++){
		printf("%d, ", Array->values[i]);
	}
	printf("]\n");
	//kElement = 3;
	kElement = rand() % (ARRAYSIZE + 1);
	printf("The %d:d smallest element\n", kElement);
	kValue = bruteSelect(Array, kElement);
	//kValue = quickSelect(Array, kElement, HOARE);
	printf("%d\n", kValue);
	system("pause");
}