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

#include "array.h"

//ALGORITHM floyd(ArrayT, range)
// for J : = N - M + 1 to N do
// T : = RandInt(1, J)
//	 if T is not in S then
//	 	insert T in S
//	 else
//	 insert J in S
void floyd(arrayT Array, int range);

#endif