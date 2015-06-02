#include "partAlg.h"
#include "array.h"
#include <stdlib.h>

static int medianOfThree(arrayT Array);

int lomutoPartition(arrayT Array, counterT counter){
	//	ALGORITHM LomutoPartition(A[l..r])
	//Partitions subarray by Lomuto’s algorithm using first element as pivot
	//Input: A subarray A[l..r] of array A[0..n − 1], defined by its left and right
	// indices l and r (l ≤ r)
	//Output: Partition of A[l..r] and the new position of the pivot
	if (Array->lIndex == Array->rIndex)
		return Array->lIndex;
	int p, s, i, median;

	median = medianOfThree(Array);
	swap(Array, median, Array->lIndex);
	
	p = Array->values[Array->lIndex];
	s = Array->lIndex;

	for (i = Array->lIndex+1; i <= Array->rIndex; i++){
		counter->lomuto->LoopCounts++;
		if (Array->values[i] < p){
			s++;
			swap(Array, s, i);
		}
	}
	swap(Array, Array->lIndex, s);
	return s;
}

int hoarePartition(arrayT Array, counterT counter){
	if (Array->lIndex == Array->rIndex)
		return Array->lIndex;
	int p, i, j;
	p = Array->values[medianOfThree(Array)];
	i = Array->lIndex;
	j = Array->rIndex;
	while (i < j){
		while (Array->values[i] < p){
			i++;
			counter->hoare->LoopCounts++;
		}
		while (Array->values[j] > p){
			j--;
			counter->hoare->LoopCounts++;
		}
		swap(Array, i, j);
	}
	swap(Array, i, j);

	return j;
}

static int medianOfThree(arrayT Array){
	int median;
	int m = Array->rIndex / 2;
	int r = Array->rIndex;
	int l = Array->lIndex;
	median = max(min(l, m), min(max(l, m), r));
	return(median);
}