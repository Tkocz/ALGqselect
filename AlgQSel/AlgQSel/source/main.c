#include <stdio.h>
#include <stdlib.h>
#include "partAlg.h"
#include "selectionAlg.h"
#include "inc/random.h"

#define ARRAYSIZE 1000

main(){
	int i;
	int Array[ARRAYSIZE];

	Randomize();
	for (i = 0; i < ARRAYSIZE; i++){
		Array[i] = RandomInteger(0, 20000);
	}
	printf("Array[");
	for (i = 0; i < ARRAYSIZE; i++){
		printf("%d, ", Array[i]);
	}
	printf("]");
}