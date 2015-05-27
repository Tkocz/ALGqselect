/*
* File: partAlg.h
* --------------
* Granssnitt för partitionering
*
* Martin Bergqvist, ASYAR14
* Senast modifierad: 27/5 - 2015
*/

#ifndef _partAlg_h
#define _partAlg_h

#include "array.h"

//ALGORITHM LomutoPartition(Array[l..r], size)
//Partitions subarray by Lomuto’s algorithm using first element as pivot
//Input: A subarray Array[l..r] of Array[0..n − 1], defined by its left and right
// indices l and r (l ≤ r)
//Output: Partition of Array[l..r] and the new position of the pivot
int lomutoPartition(arrayT Array);


//ALGORITHM HoarePartition(A[l..r])
//Partitions a subarray by Hoare’s algorithm, using the first element
// as a pivot
//Input: Subarray of array A[0..n − 1], defined by its left and right
// indices l and r (l<r)
//Output: Partition of A[l..r], with the split position returned as
// this function’s value
int hoarePartition(arrayT Array);

#endif