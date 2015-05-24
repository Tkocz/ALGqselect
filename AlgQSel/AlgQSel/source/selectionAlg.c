#include "selectionAlg.h"

int quickSelect(int *Array, int n, int k){
	int *subArray;
	int i;
	s = LomutoPartition(Array[l..r], n); //or another partition algorithm
	if (s == k - 1)
		return Array[s];
	else if (s > l + k - 1){
		subArray = NewArray(s, int);
		for (i = 0; i < s; i++){
			subArray[i] = Array[i];
		}
		quickSelect(subArray, s, k);
	}
	else{
		subArray = NewArray((n-s), int);
		for (i = s; i < n; i++){
			subArray[i] = Array[i];
		}
		quickSelect(Array, (n-s), (k-1-s));
	}
}

//ALGORITHM Bruteselect(Array[l..r], n, k)
int bruteSelect(int *Array, int n, int k){
	int i, j, *kLowest;
	kLowest = NewArray(k+1, int);
	kLowest[0], kLowest[k] = 999999;

	for (j = 0; j < k; j++){
		for (i = 0; i < n; i++){
			if (Array[i] < kLowest[j] && Array[i] > kLowest[j+1])
				kLowest[j] = Array[i];
		}
	}
	return Array[k];
}