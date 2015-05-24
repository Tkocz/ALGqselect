
int lomutoPartition(int *Array, int n){
	int i, p, s, tmp;
	
	p = medianOfThree(Array, n); //skall sättas till median-of-three
	s = 0;
	for (i = 0; i < n; i++){
		if (Array[i] < p){
			s++;
			tmp = Array[s];
			Array[s] = Array[i];
			Array[i] = tmp;
		}
	}
	tmp = Array[0];
	Array[0] = Array[s];
	Array[s] = tmp;
	return s;
}


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

//ALGORITHM medianOfThree(Array, n)
//Returns the median of the first, last and middle element from Array.
static int medianOfThree(int *Array, int n){

	if (Array[0] < Array[n] && Array[0] < Array[n / 2])
		if (Array[n] > Array[n / 2])
			return Array[n / 2];
		else
			return Array[n];
	else if (Array[n] < Array[n / 2] && Array[n] < Array[0])
		if (Array[n / 2] > Array[0])
			return Array[0];
		else
			return Array[n / 2];
	else if (Array[n / 2] < Array[0] && Array[n / 2] < Array[n])
		if (Array[0] > Array[n])
			return Array[n];
		else
			return Array[0];
}