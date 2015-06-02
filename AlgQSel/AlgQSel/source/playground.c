#include "playground.h"
#include "array.h"
#include "sequencer.h"
#include <stdio.h>
#include "selectionAlg.h"
#include "analyzer.h"
#include <string.h>

void playGround(void){
	arrayT Array, origArray;
	int kValue=0, size=0, range=0;
	int result[3] = { 0 };
	char choice = ' ';
	char printChoice = ' ';
	counter = initCounter();
	printf("Enter an arraysize:\n");
	while (size < 1)
		scanf("%d", &size);

	printf("Enter what order to search for: \n");
	while (kValue < 1)
		scanf("%d", &kValue);

	printf("Enter range for the elements: \n");
	while (range < size){
		scanf("%d", &range);
		if (range < size)
			printf("Range must be equal to, or greater than the arraysize\n");
	}
	origArray = newArrayT(size);
	Array = newArrayT(size);
	sequencer(origArray, range);
	restoreArray(Array, origArray);

	printf("What method do you wish to use to find your element\n");
	printf("Quickselect with Lomuto, Quickselect with Hoare's, BruteSelect, or all of them?\n");
	printf("Select ( l / h / b / a )\n");
	while (!(choice == 'l' || choice == 'h' || choice == 'b' || choice == 'a')){
		choice = getchar();
	}
	printf("Do you wish to print out your array? (y/n)\n");
	while (!(printChoice == 'y' || printChoice == 'n'))
		printChoice = getchar();
	if (printChoice == 'y')
		printArray(Array);

	if(choice == 'l'){ 
		result[0] = quickSelect(Array, kValue, LOMUTO, counter);
		printf("The element you sought is %d\n", result[0]);
	}
	else if (choice == 'h'){
		result[0] = quickSelect(Array, kValue, HOARE, counter);
		printf("The element you sought is %d\n", result[0]);
	}
	else if (choice == 'b'){
		result[0] = bruteSelect(Array, kValue, counter);
		printf("The element you sought is %d\n", result[0]);
	}
	else if (choice == 'a'){
		result[0] = quickSelect(Array, kValue, LOMUTO, counter);
		restoreArray(Array, origArray);
		result[1] = quickSelect(Array, kValue, HOARE, counter);
		restoreArray(Array, origArray);
		result[2] = bruteSelect(Array, kValue, counter);
		printf("The element you sought is %d, %d, %d\n", result[0], result[1], result[2]);
	}
	else exit(0);
}