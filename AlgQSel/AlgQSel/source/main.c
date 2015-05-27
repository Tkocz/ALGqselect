#include <stdio.h>
#include "partAlg.h"
#include "selectionAlg.h"
#include "floyd.h"
#include "array.h"

#define ARRAYSIZE	1000				//RANGE have to be defined as *at least* ARRAYSIZE
#define RANGE		1000				//as every element needs to be unique.

main(){

	arrayT Array;
	int i, kElement, kValue;

	Array = newArrayT(ARRAYSIZE);
	floyd(Array, RANGE);
	
	printf("Array[");
	for (i = 0; i < ARRAYSIZE; i++){
		printf("%d, ", Array->values[i]);
	}
	printf("]\n");


	kElement = 3;
	//kElement = rand() % (ARRAYSIZE + 1);
	printf("The %d:d smallest element\n", kElement);

	//kValue = bruteSelect(Array, kElement);
	kValue = quickSelect(Array, kElement);
	printf("%d\n", kValue);
	

	
}
