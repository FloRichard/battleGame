#include "../../header/structs/structs.h"
#include "../../header/funcs/funcs.h"

/**
 *	fillDeck will fill the deck with cards of the given value and colors.
 *
 */
void fillDeck(deck* d) {
	int index = 0;
	for (int i=0; i<NB_COLORS; i++) {
		for (int j=0; j<NB_VALUES; j++) {
			fillCard(&d->cards[index++], values[j], colors[i], j+1);
		}
	}
}

/**
 * fillCard will fill a card with the givne value, color and height.
 *
 */
void fillCard(card *c, char value[], char color[], int height) {
	for (int i=0; i<MAX_STR_SIZE; i++) {
		c->value[i] = value[i];
	}

	for (int i=0; i<MAX_STR_SIZE; i++) {
		c->color[i] = color[i];
	}
	
	//check if the value is As	
	if (height == 1) {
		c->height = 14;
	} else {
		c->height = height;
	}	
}