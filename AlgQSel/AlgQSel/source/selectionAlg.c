#include "selectionAlg.h"

int quickSelect(arrayT Array, int kValue, int partAlg, counterT counter){
	int s;

	if (partAlg){
		counter->hoare->recursions++;
		s = hoarePartition(Array, counter);
	}
	else{
		counter->lomuto->recursions++;
		s = lomutoPartition(Array, counter);
	}

	if (s == kValue - 1)
		return (Array->values[s]);
	else if (s > (kValue - 1)){
		Array->rIndex = s - 1;
		quickSelect(Array, kValue, partAlg, counter);
	}
	else{
		Array->lIndex = s + 1;
		quickSelect(Array, (kValue), partAlg, counter);
	}
}

//ALGORITHM Bruteselect(arrayT, k)
int bruteSelect(arrayT Array, int kValue, counterT counter){
	int i, j;
	counter->brute->LoopCounts = 0;

	for (j = 0; j < kValue; j++){
		for (i = j; i <= Array->rIndex; i++){
			if (Array->values[i] < Array->values[j]){
				swap(Array, i, j);
			}
			counter->brute->LoopCounts++;
		}
	}
	return Array->values[kValue-1];
}