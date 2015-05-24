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
//Solves the selection problem by bubblesorting, and then 
// selecting the k:th element from the sorted list.
//Input: Subarray A[l..r] of array A[0..n − 1] of orderable elements and
// integer k (1 <= k <= r − l + 1)
//Output: The value of the kth smallest element in A[l..r]

/*
int bruteselect(int A[]){
int i, j, temp;
int size = sizeof(A[])
for(i=0; i <= size; i++){
for(j=i; j <=size; j++){
if(A[i]>A[j]){
temp = A[i];
A[i] = A[j];
A[j] = temp;
}
}
}
}
return(A[k]);
}
*/