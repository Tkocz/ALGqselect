#include <stdio.h>
#include "partAlg.h"
#include "selectionAlg.h"
#include "floyd.h"
#include "array.h"
#include "analyzer.h"
#include "playground.h"

main(){
	char answer;
	while (1){
		system("cls");
		printf("Anaylyzing tool intended for Quickselect.\nCreated by Martin Bergqvist, S141564 @ HB.se\n");
		printf("Would you like to run the analysis mode, or play around? a/p (q to quit)\n");
		answer = ' ';
		while (!(answer == 'a' || answer == 'p' || answer == 'q'))
			answer = getchar();
		if (answer == 'a')
			timer();
		else if (answer == 'p')
			playGround();
		else 
			break;
	}
}
