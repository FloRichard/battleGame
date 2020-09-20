#include <stdio.h>
#include <string.h>
#include "../../header/structs/structs.h"
#include "../../header/funcs/funcs.h"

char colors[NB_COLORS][MAX_STR_SIZE] = {"coeur","trefle","pique","carreau"};
char values[NB_VALUES][MAX_STR_SIZE] = {"As","Deux","Trois","Quatre","Cinq","Six","Sept","Huit","Neuf","Dix","Valet","Dame","Roi"};

/**
 * printDeck will print the deck from the first card to the last.
 *
 */
void printDeck(deck* d){
	for (int i=0; i<DECK_SIZE;i++) {
		printCard(d->cards[i].value, d->cards[i].color);
		printf(" height = %d",d->cards[i].height);
		printf("\n");
	}
}

/**
 * printCard will print a card with its value and color.
 *
 */
void printCard(char value[], char color[]) {
	if (color[0] != 'c' && color[0] != 't' && color[0] != 'p') {
		return;
	}

	for (int i=0; i< MAX_STR_SIZE; i++) {
		if (value[i] == '\0') {
			break;
		}
		printf("%c", value[i]);
	}	
	
	printf(" de ");	
	
	for (int i=0; i< MAX_STR_SIZE; i++){
		if (color[i] == '\0') {
			break;
		}		
		printf("%c", color[i]);
	}
}

/**
 *	printHands print both player one and player two hands.
 *	Mostly for debug purpose.
 */
void printHands(deck* playerOne, deck* playerTwo, int greaterSize){
	for (int i=0; i<greaterSize; i++) {
		if (i < 9){
			printf("%d.   ",i+1);
		} else {
			printf("%d.  ",i+1);		
		}
			
		printCard(playerOne->cards[i].value, playerOne->cards[i].color);
	
		int stringSize = strlen(playerOne->cards[i].color) + strlen(playerOne->cards[i].value) + 4;
		if (stringSize < 10) {
			stringSize = 0;
		}

		// 25 is the greater string possible (color + value + blanks).
		for (int i=0; i<25-stringSize ;i++) {
			printf(" ");
		}

		printf("|-----------------|        ");
		
		printCard(playerTwo->cards[i].value, playerTwo->cards[i].color);
		
		printf("\n");
	}
}