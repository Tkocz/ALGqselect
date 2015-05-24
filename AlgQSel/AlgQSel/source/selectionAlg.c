#include "selectionAlg.h"
#include "partAlg.h"

int quickSelect(int *Array, int n, int k){
	int *subArray;
	int i, s;
	s = 0;// lomutoPartition(*Array, n); //or another partition algorithm
	if (s == k - 1)
		return Array[s];
	else if (s > (k - 1)){
		subArray = NewArray(s, int);
		for (i = 0; i <= s; i++){
			subArray[i] = Array[i];
		}
		quickSelect(subArray, s, k);
	}
	else{
		subArray = NewArray((n-s), int);
		int j = 0;
		for (i = s+1; i <= n; i++){
			subArray[j] = Array[i];
			j++;
		}
		quickSelect(subArray, j, (k-1-s));
	}
}

//ALGORITHM Bruteselect(Array[l..r], n, k)
int bruteSelect(int *Array, int n, int k){
	int i, j, *kLowest;
	kLowest = NewArray(k, int);
	for (i = 0; i <= k; i++){
		kLowest[i] = 999999;
	}

	for (j = 0; j <= k; j++){
		for (i = 0; i < n; i++){
			if (Array[i] < kLowest[j] && (Array[i] > kLowest[j-1] || kLowest[0] == 999999))
				kLowest[j] = Array[i];
		}
	}
	return kLowest[k-1];
}