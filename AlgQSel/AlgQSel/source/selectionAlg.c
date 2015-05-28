#include "selectionAlg.h"

int quickSelect(arrayT Array, int kValue, int partAlg){

	int i, s, tmp;

/*	if (Array->lIndex > Array->rIndex){
		tmp = Array->lIndex;
		Array->lIndex = Array->rIndex;
		Array->rIndex = tmp;
	}*/

	if (partAlg)
		s = hoarePartition(Array);
	else
		s = lomutoPartition(Array);

	if (s == kValue - 1)
		return (Array->values[s]);
	else if (s > (Array->lIndex + kValue - 1)){
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
	int i, j, tmp, *kLowest;
	tmp = 0;
	kLowest = malloc(sizeof(int)*k);

	for (i = 0; i <= k; i++){
		kLowest[i] = 999999;
	}

	for (j = 0; j <= k; j++){
		for (i = 0; i < Array->nValues; i++){
			if (Array->values[i] < kLowest[j]){
				kLowest[j] = Array->values[i];
				tmp = i;
			}
		}
		Array->values[tmp] = kLowest[k];
	}
	return kLowest[k - 1];
}