#include "inc/genlib.h"
#include <stdio.h>
#include <stdlib.h>


#define M 10
#define N 100    

int* floyd(int Array[], int length, int range){
	int *is_used;
	int i;
	is_used = NewArray(length, int);
	for (i = 0; i < length; i++)
		is_used[i] = 0;

	int in, im;

	im = 0;

	for (in = range -length; in < range && im < length; ++in) {
		int r = rand() % (N + 1); /* generate a random number 'r' */

		while (is_used[r])
		{
			/* we already have 'r' */
			r = rand() % (N + 1);
		}
		Array[im++] = r + 1; /* +1 since your range begins from 1 */
		is_used[r] = 1;
	}
}