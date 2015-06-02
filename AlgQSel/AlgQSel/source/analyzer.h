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
#define RANGE		9999				//as every element needs to be unique.

typedef struct algTrackT {
	double timer;
	int recursions;
	int LoopCounts;
} *algTrackT;

typedef struct counterT {
	int			numReps;
	algTrackT	lomuto;
	algTrackT	hoare;
	algTrackT	brute;
} *counterT;

typedef char *string;

static counterT counter;

void performance(void);

#endif