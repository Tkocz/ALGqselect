﻿#include "partAlg.h"
#include "array.h"
#include <stdlib.h>

static int medianOfThree(arrayT Array);

int lomutoPartition(arrayT Array, counterT counter){
	//	ALGORITHM LomutoPartition(A[l..r])
	//Partitions subarray by Lomuto’s algorithm using first element as pivot
	//Input: A subarray A[l..r] of array A[0..n − 1], defined by its left and right
	// indices l and r (l ≤ r)
	//Output: Partition of A[l..r] and the new position of the pivot
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

//ALGORITHM medianOfThree(Array, n)
//Returns the median of the first, last and middle element from Array.
/*static int medianOfThree(arrayT Array){
	if (Array->rIndex - Array->lIndex < 3)
		return Array->lIndex;

	int m = Array->rIndex / 2;
	int r = Array->rIndex;
	int l = Array->lIndex;

	if (Array->values[l] < Array->values[m])
	{
		if (Array->values[l] >= Array->values[r])
			return l;
		else if (Array->values[m] < Array->values[r])
			return m;
	}
	else
	{
		if (Array->values[l] < Array->values[r])
			return l;
		else if (Array->values[m] >= Array->values[r])
			return m;
	}
	return r;
}*/
static int medianOfThree(arrayT Array){
	int median;
	int m = Array->rIndex / 2;
	int r = Array->rIndex;
	int l = Array->lIndex;
	median = max(min(l, m), min(max(l, m), r));
	return(median);
}