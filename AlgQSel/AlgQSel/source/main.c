#include <stdio.h>
#include <stdlib.h>
#include "partAlg.h"
#include "selectionAlg.h"
#include "inc/random.h"
#include "floyd.h"

#define ARRAYSIZE	100
#define RANGE		100

main(){
	int i;
	int Array[ARRAYSIZE];
	floyd(Array, ARRAYSIZE, RANGE);
	prinft("Array[");
	for (i = 0; i < ARRAYSIZE; i++){
		printf("%d, ", Array[i]);
		}
	printf("]");
}
