/*
* File: analyzer.h
* --------------
* Interface for analyzing efficiency and timeconsumption on algorithms
*
* Martin Bergqvist, ASYAR14
* Senast modifierad: 27/5 - 2015
*/
#ifndef _analyzer_h_
#define _analyzer_h_

#define NUMBEROFREPS 30

#define ARRAYSIZE	10				//RANGE have to be defined as *at least* ARRAYSIZE
#define RANGE		200				//as every element needs to be unique.

void timer(void);

#endif