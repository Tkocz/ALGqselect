//ALGORITHM LomutoPartition(A[l..r])
//Partitions subarray by Lomuto’s algorithm using first element as pivot
//Input: A subarray A[l..r] of array A[0..n − 1], defined by its left and right
// indices l and r (l ≤ r)
//Output: Partition of A[l..r] and the new position of the pivot

/*
int lomutoPartition(){
p←A[l] //skall sättas till median-of-three
s ←l
for i ←l + 1 to r do
if A[i]<p
s ←s + 1; swap(A[s], A[i])
swap(A[l], A[s])
return s
}
*/

//ALGORITHM HoarePartition(A[l..r])
//Partitions a subarray by Hoare’s algorithm, using the first element
// as a pivot
//Input: Subarray of array A[0..n − 1], defined by its left and right
// indices l and r (l<r)
//Output: Partition of A[l..r], with the split position returned as
// this function’s value

/*
int hoarePartition(){
	p = A[l] //skall sattas till median-of-three
	i = l; j = r + 1
	repeat
		repeat i = i + 1 until A[i]=> p
		repeat j = j − 1 until A[j]<= p
		swap(A[i], A[j])
	until i => j
	swap(A[i], A[j]) //undo last swap when i => j
	swap(A[l], A[j])
	return j
}
*/