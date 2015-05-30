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

#define ARRAYSIZE	1000				//RANGE have to be defined as *at least* ARRAYSIZE
#define RANGE		1250				//as every element needs to be unique.

typedef struct counterT {
	int *lomuto;
	int *hoare;
	int *brute;
	int nReps;
} *counterT;

void initCounter(void);

void timer(void);

#endif