#include <stdio.h>
#include "partAlg.h"
#include "selectionAlg.h"
#include "floyd.h"

#define ARRAYSIZE	10				//RANGE have to be defined as at least ARRAYSIZE
#define RANGE		100				//as every element needs to be unique.

main(){
	int i, kElement, kValue;
	int Array[ARRAYSIZE];
	floyd(Array, ARRAYSIZE, RANGE);
	
	kElement = 3;
	//kElement = rand() % (ARRAYSIZE + 1);
	printf("%d\n", kElement);

	//kValue = bruteSelect(Array, ARRAYSIZE, kElement);
	kValue = quickSelect(Array, ARRAYSIZE, kElement);
	printf("%d\n", kValue);
	
	printf("Array[");
	for (i = 0; i < ARRAYSIZE; i++){
		printf("%d, ", Array[i]);
		}
	printf("]");
	
}
