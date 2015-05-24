#include <stdlib.h>
#include "partAlg.h"
#include "selectionAlg.h"
#include "genlib.h"

//ALGORITHM Quickselect(A[l..r], k)
//Solves the selection problem by recursive partition-based algorithm
//Input: Subarray A[l..r] of array A[0..n − 1] of orderable elements and
// integer k (1<= k <= r − l + 1)
//Output: The value of the kth smallest element in A[l..r]

/*
int quickselect(){
s  = LomutoPartition(A[l..r]) //or another partition algorithm
if s = k − 1 return A[s]
else if s > l + k − 1 Quickselect(A[l..s − 1], k)
else Quickselect(A[s + 1..r], k − 1− s)
}
*/

//ALGORITHM Bruteselect(A[l..r], k)
//Solves the selection problem by traversing the array, finding the smallest
// element not previously found, and repeating k times.  
//Input: Array A[0..n − 1] of orderable unique elements and
// integer k (1 <= k <= r − l + 1)
//Output: The value of the kth smallest element in A[l..r]


int bruteSelect(int A[], int k){
	int i, j, *kLowest;

	kLowest = 999999;
	for (j = 1, j <= k, j++){
		for (i = 0, i < n, i++){
			if (A[i] < kLowest[j] && A[i] < kLowest[j - 1]) kLowest[j] = A[i];
		}
	}
}