#include "partAlg.h"
#include "inc/simpio.h"

static int medianOfThree(int *Array, int n);

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


int hoarePartition(int *Array, int n){
	int p, i, j, tmp;
	
	p = medianOfThree(Array, n); //skall sattas till median-of-three
	i = 0;
	j = n + 1;
	while (i >= j){
		while (Array[i] >= p)
			i = i + 1;
		while (Array[j] <= p)
			j = j-1;
		tmp = Array[i];
		Array[i] = Array[j];
		Array[j] = tmp;
	}
	tmp = Array[i];
	Array[i] = Array[j];
	Array[j] = tmp;

	tmp = Array[0];
	Array[0] = Array[j];
	Array[j] = tmp;

	return j;
}

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
	else Error("Unexpected order");
}