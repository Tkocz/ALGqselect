﻿/*
* File: selectionAlg.h
* --------------
* Granssnitt för partitionering
*
* Martin Bergqvist, ASYAR14
* Senast modifierad: 17/5 - 2015
*/

#ifndef _pqueue_h
#define _pqueue_h

#include <stdio.h>
#include "partAlg.h"
#include "inc/genlib.h"
#include "inc/simpio.h"

//ALGORITHM Quickselect(Array[l..r], n, k)
//Solves the selection problem by recursive partition-based algorithm
//Input: Subarray Array[l..r] of Array[0..n − 1] of orderable unique elements,
// size of array (n) and integer k ( 1 <= k <= (r − l + 1))
//Output: The value of the kth smallest element in Array[l..r]
int quickSelect(int *Array, int n, int k);


//ALGORITHM Bruteselect(Array[l..r], n, k)
//Solves the selection problem by traversing the array, finding the smallest
// element not previously found, and repeating k times.  
//Input: Array[0..n − 1] of orderable unique elements, size of Array (n) and
// integer k (1 <= k <= (r − l + 1))
//Output: The value of the kth smallest element in Array[l..r]
int bruteSelect(int *Array, int n, int k);

#endif