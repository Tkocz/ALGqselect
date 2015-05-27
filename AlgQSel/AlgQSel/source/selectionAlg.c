#include "selectionAlg.h"

int quickSelect(arrayT Array, int k, int partAlg){
	
	if (Array->nValues == 1)
		return Array->values[0];
	
	arrayT subArray;
	int i, s;
	
	if (partAlg)
		s = hoarePartition(Array);
	else
		s = lomutoPartition(Array);

	if (s == k - 1)
		return Array->values[s];
	else if (s > (k - 1)){
		subArray = malloc(sizeof(arrayT));
		subArray->nValues = s;
		subArray->values = malloc(sizeof(int)*s);
		for (i = 0; i <= s; i++){
			subArray->values[i] = Array->values[i];
		}
		quickSelect(subArray, k, partAlg);
	}
	else{
		subArray = malloc(sizeof(arrayT));
		subArray->nValues = (Array->nValues - s);
		subArray->values = malloc(sizeof(int)*(Array->nValues - s));
		int j = 0;
		for (i = s+1; i <= Array->nValues; i++){
			subArray->values[j] = Array->values[i];
			j++;
		}
		quickSelect(subArray, (k-1-s), partAlg);
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

	for (j = 1; j <= k; j++){
		for (i = 0; i < Array->nValues; i++){
			if (Array->values[i] < kLowest[j]){
				kLowest[j] = Array->values[i];
				tmp = i;
			}
		}
		Array->values[tmp] = kLowest[k];
	}
	return kLowest[k];
}