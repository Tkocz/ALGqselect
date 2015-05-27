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
	
	p = Array->values[0];
	s = 0;
	for (i = 0; i < Array->nValues; i++){
		if (Array->values[i] < p){
			s++;
			swap(Array, s, i);
		}
	}
	swap(Array, 0, s);
	return s;
}

int hoarePartition(arrayT Array){
	int p, i, j;
	p = Array->values[medianOfThree(Array)];
	i = 0;
	j = Array->nValues-1;
	while (i < j){
		while (Array->values[i] < p)
			i++;
		while (Array->values[j] > p)
			j--;
		swap(Array, i, j);
	}
	swap(Array, i, j);
	//swap(Array, 0, j);

	return j;
}

//ALGORITHM medianOfThree(Array, n)
//Returns the median of the first, last and middle element from Array.
static int medianOfThree(arrayT Array){
	int n = Array->nValues-1;
	if (Array->values[0] <= Array->values[n] && Array->values[0] <= Array->values[n / 2])
		if (Array->values[n] > Array->values[n / 2])
			return (n / 2);
		else
			return n;
	else if (Array->values[n] <= Array->values[n / 2] && Array->values[n] <= Array->values[0])
		if (Array->values[n / 2] > Array->values[0])
			return 0;
		else
			return (n / 2);
	else //if (Array->values[n / 2] <= Array->values[0] && Array->values[n / 2] <= Array->values[n])
		if (Array->values[0] > Array->values[n])
			return n;
		else
			return 0;
}