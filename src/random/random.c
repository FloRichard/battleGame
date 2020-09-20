#include <stdlib.h>
#include <stdbool.h>
#include "../../header/structs/structs.h"
#include "../../header/funcs/funcs.h"

/**
 * getRandomInt generates a random int used for card index.
 * The function assure that each index returned haven't been already generated.
 */
int getRandomInt(int rands[], int index){
	int min_value_flag = 0;
	int max_value_flag = 0;
	
	int c = (int) (rand() % (DECK_SIZE));
	while (randIsAlreadyTaken(rands, index, c)) {
		if (c == 0) {
			min_value_flag = 1;
		}
		if (c == DECK_SIZE-1) {
			max_value_flag = 1;
		}

		if (min_value_flag == 0) {
			c -= 1;
		}else if (max_value_flag == 0) {
			c += 1;
		}	
	}
	
	rands[index] = c;
	return c;	
}

/**
 * randIsAlreadyTaken checks if a given int has already been generate.
 *
 */
bool randIsAlreadyTaken(int rands[],  int index, int c){
	for (int i=0; i<index; i++) {
		if (rands[i] == c) {
			return true;
		}
	}

	return false;
}