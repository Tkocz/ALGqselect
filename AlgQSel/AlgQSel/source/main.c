#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include "partAlg.h"
#include "selectionAlg.h"
#include "sequencer.h"
#include "array.h"
#include "analyzer.h"
#include "playground.h"


main(){
	//srand(time(NULL));
	while (1){
		char answer;
		system("cls");
		printf("Anaylyzing tool intended for Quickselect.\nCreated by Martin Bergqvist, S141564 @ HB.se\n");
		printf("Would you like to run the analysis mode, or play around? a/p (q to quit)\n");
		answer = ' ';
		while (!(answer == 'a' || answer == 'p' || answer == 'q')){
			answer = getchar();
			if (answer == 'a'){
				performance();
				break;
			}
			else if (answer == 'p'){
				playGround();
				break;
			}
			else if (answer == 'q'){
				exit(0);
			}
		}
	}
}
