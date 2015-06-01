#include "playground.h"
#include "array.h"
#include "sequencer.h"
#include <stdio.h>
#include "selectionAlg.h"
#include "analyzer.h"
#include <string.h>

void playGround(void){

	arrayT Array, origArray;
	int i, kElement, kValue;
	origArray = newArrayT(ARRAYSIZE);
	sequencer(origArray, RANGE);
	Array = newArrayT(ARRAYSIZE);
	memcpy(Array->values, origArray->values, sizeof(int)*ARRAYSIZE);

	printf("Array[");
	for (i = 0; i < ARRAYSIZE; i++){
		printf("%d, ", Array->values[i]);
	}
	printf("]\n");
	//kElement = 3;
	kElement = rand() % (ARRAYSIZE + 1);
	printf("The %d:d smallest element\n", kElement);
	kValue = bruteSelect(Array, kElement, NULL);
	//kValue = quickSelect(Array, kElement, HOARE);
	printf("%d\n\n", kValue);

	memcpy(Array->values, origArray->values, sizeof(int)*ARRAYSIZE);
	printf("Array[");
	for (i = 0; i < ARRAYSIZE; i++){
		printf("%d, ", Array->values[i]);
	}
	printf("]\n");
	system("pause");
}