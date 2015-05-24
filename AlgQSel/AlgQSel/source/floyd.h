/*
* File: floyd.h
* --------------
* Granssnitt för generering av slumpmässig, unik array
*
* Martin Bergqvist, ASYAR14
* Senast modifierad: 17/5 - 2015
*/

#ifndef _floyd_h
#define _floyd_h

//ALGORITHM floyd(lenght, range)
//Generates an array of *lenght*, and fills it with random unique integers
// up to the *range*
//Output: array[length] with values in the range of 0 to range
int* floyd(int Array[], int length, int range);

#endif