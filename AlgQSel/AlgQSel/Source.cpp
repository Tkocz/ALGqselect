/*
//ALGORITHM Quickselect(A[l..r], k)
//Solves the selection problem by recursive partition-based algorithm
//Input: Subarray A[l..r] of array A[0..n − 1] of orderable elements and
// integer k (1≤ k ≤ r − l + 1)
//Output: The value of the kth smallest element in A[l..r]
//s ←LomutoPartition(A[l..r]) //or another partition algorithm
//if s = k − 1 return A[s]
//else 
//	if s > l + k − 1 
//		Quickselect(A[l..s − 1], k)
//else 
//	Quickselect(A[s + 1..r], k − 1− s)








median(int a[], int p, int r)
{
	int m = (p + r) / 2;
	if (a[p] < a[m])
	{
		if (a[p] >= a[r])
			return a[p];
		else if (a[m] < a[r])
			return a[m];
	}
	else
	{
		if (a[p] < a[r])
			return a[p];
		else if (a[m] >= a[r])
			return a[m];
	}
	return a[r];
}*/