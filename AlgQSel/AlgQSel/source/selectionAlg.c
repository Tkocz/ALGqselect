#include "selectionAlg.h"

int quickSelect(arrayT Array, int kValue, int partAlg){

	int s;

	if (partAlg)
		s = hoarePartition(Array);
	else
		s = lomutoPartition(Array);

	if (s == kValue - 1)
		return (Array->values[s]);
	else if (s > (kValue - 1)){
		Array->rIndex = s - 1;
		quickSelect(Array, kValue, partAlg);
	}
	else{
		Array->lIndex = s + 1;
		quickSelect(Array, (kValue), partAlg);
	}
}

//ALGORITHM Bruteselect(arrayT, k)
int bruteSelect(arrayT Array, int k){
	int i, j, counter;
	counter = 0;

	for (j = 0; j < k; j++){
		for (i = j; i <= Array->rIndex; i++){
			if (Array->values[i] < Array->values[j]){
				swap(Array, i, j);
			}
			counter++;
		}
	}
	return Array->values[k-1];
}