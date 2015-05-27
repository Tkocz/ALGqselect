#include "partAlg.h"
#include "inc/simpio.h"
#include "array.h"

static int medianOfThree(arrayT Array);

int lomutoPartition(arrayT Array){
	int i, p, s, tmp;
	
	p = medianOfThree(Array);
	s = 0;
	for (i = 0; i < Array->nValues; i++){
		if (Array->values[i] < p){
			s++;
			tmp = Array->values[s];
			Array->values[s] = Array->values[i];
			Array->values[i] = tmp;
		}
	}
	tmp = Array->values[0];
	Array->values[0] = Array->values[s];
	Array->values[s] = tmp;
	return s;
}


int hoarePartition(arrayT Array){
	int p, i, j, tmp;
	tmp = 0;
	p = Array->values[medianOfThree(Array)];
	i = 0;
	j = Array->nValues+1;
	while (i <= j){
		while (Array->values[i++] <= p)
		while (Array->values[j--] >= p)
		tmp = Array->values[i];
		Array->values[i] = Array->values[j];
		Array->values[j] = tmp;
	}
	tmp = Array->values[i];
	Array->values[i] = Array->values[j];
	Array->values[j] = tmp;

	tmp = Array->values[0];
	Array->values[0] = Array->values[j];
	Array->values[j] = tmp;

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
	else if (Array->values[n / 2] <= Array->values[0] && Array->values[n / 2] <= Array->values[n])
		if (Array->values[0] > Array->values[n])
			return n;
		else
			return 0;
	else Error("Unexpected order");
}