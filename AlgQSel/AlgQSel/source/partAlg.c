#include "partAlg.h"
#include "array.h"
#include <stdlib.h>

static int medianOfThree(arrayT Array);

int lomutoPartition(arrayT Array){
	//	ALGORITHM LomutoPartition(A[l..r])
	//Partitions subarray by Lomuto’s algorithm using first element as pivot
	//Input: A subarray A[l..r] of array A[0..n − 1], defined by its left and right
	// indices l and r (l ≤ r)
	//Output: Partition of A[l..r] and the new position of the pivot
	int p, s, i;
	
	p = Array->values[Array->lIndex];
	s = Array->lIndex;
	for (i = Array->lIndex+1; i <= Array->rIndex; i++){
		if (Array->values[i] < p){
			s++;
			swap(Array, s, i);
		}
	}
	swap(Array, Array->lIndex, s);
	return s;
}

int hoarePartition(arrayT Array){
	int p, i, j;
	p = Array->values[medianOfThree(Array)];
	i = Array->lIndex;
	j = Array->rIndex + 1;
	while (i <= j){
		while (Array->values[i] <= p)
			i++;
		while (Array->values[j] >= p)
			j--;
		swap(Array, i, j);
	}
	swap(Array, i, j);
	//swap(Array, Array->lIndex, j);

	return j;
}

//ALGORITHM medianOfThree(Array, n)
//Returns the median of the first, last and middle element from Array.
static int medianOfThree(arrayT Array){
	int m = Array->nValues / 2;
	int r = Array->nValues-1;

	if (Array->values[0] < Array->values[m])
	{
		if (Array->values[0] >= Array->values[r])
			return 0;
		else if (Array->values[m] < Array->values[r])
			return m;
	}
	else
	{
		if (Array->values[0] < Array->values[r])
			return 0;
		else if (Array->values[m] >= Array->values[r])
			return m;
	}
	return r;
}