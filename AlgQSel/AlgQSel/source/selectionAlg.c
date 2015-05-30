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
	int i, j, tmp,kLowestResult, *kLowest;
	tmp = 0;
	kLowest = calloc(k+1, sizeof(int));

	for (i = 0; i <= k; i++){
		kLowest[i] = 999999;
	}

	for (j = 0; j <= k; j++){
		for (i = 0; i < Array->rIndex; i++){
			if (Array->values[i] < kLowest[j]){
				kLowest[j] = Array->values[i];
				tmp = i;
			}
		}
		Array->values[tmp] = kLowest[k];
	}
	kLowestResult =  kLowest[k - 1];
	free(kLowest);

	return kLowestResult;

}