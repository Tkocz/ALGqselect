#include "selectionAlg.h"

int quickSelect(arrayT Array, int k, int partAlg){

	arrayT subArray;
	int i, s;

	if (partAlg)
		s = hoarePartition(Array);
	else
		s = lomutoPartition(Array);

	if (s == k - 1)
		return (Array->values[s]);
	else if (s > (k - 1)){

		subArray = newSubArrayT(Array, s, k);
		quickSelect(subArray, k, partAlg);
	}
	else{

		subArray = newSubArrayT(Array, s, k);
		quickSelect(subArray, (k - 1 - s), partAlg);
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