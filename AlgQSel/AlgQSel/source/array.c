#include "array.h"
#include <stdlib.h>

arrayT newArrayT(int n) {
	arrayT array = malloc(sizeof(arrayT));

	array->values = malloc(sizeof(int)*n);
	array->nValues = n;
	return array;
}
void swap(arrayT Array, int x, int y){
	int tmp;
	tmp = Array->values[x];
	Array->values[x] = Array->values[y];
	Array->values[y] = tmp;
}
arrayT newSubArrayT(arrayT Array, int s, int k){
	int i, j;
	arrayT subArray = malloc(sizeof(arrayT));

	if (s > (k - 1)){
		subArray = malloc(sizeof(arrayT));
		subArray->nValues = s;
		subArray->values = malloc(sizeof(int)*s);
		printf("Array[");
		for (i = 0; i < s; i++){
			subArray->values[i] = Array->values[i];
			printf("%d, ", subArray->values[j]);
		}
	}
	else{
		subArray = malloc(sizeof(arrayT));
		subArray->nValues = (Array->nValues - s);
		subArray->values = malloc(sizeof(int)*(Array->nValues - s));
		int j = 0;
		printf("Array[");
		for (i = s + 1; i < Array->nValues; i++){
			subArray->values[j] = Array->values[i];
			printf("%d, ", subArray->values[j]);
			j++;
		}
	}
	return subArray;
}