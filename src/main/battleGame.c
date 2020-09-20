#include <stdio.h>
#include <time.h>
#include <stdlib.h>
#include "../../header/structs/structs.h"
#include "../../header/funcs/funcs.h"

#define NB_COLORS 4
#define NB_VALUES 13

int main(){
	deck initDeck;
	deck playerOne;
	deck playerTwo;

	srand((long) time(NULL));

	printf("------------- filling deck ------------\n");
	fillDeck(&initDeck);
	printDeck(&initDeck);
	printf("------------- deck filled -------------\n");
	int cardIsNil(card c);
	printf("------------- shuffling deck ----------\n");
	deck shuffledDeck = shuffleDeck(&initDeck);		
	printDeck(&shuffledDeck);
	printf("------------- deck shuffled -----------\n");
	
	printf("------------- dealing cards -----------\n");
	dealCards(&shuffledDeck, &playerOne, &playerTwo);
	printHands(&playerOne, &playerTwo, DECK_SIZE/2);
	printf("------------- cards dealed ------------\n");
	
	printf("\n\n------------- game start --------------\n");
	printf("\n");
	printf("\n");
	
	while(!itsWon(playerOne, playerTwo)){
	    playTurn(&playerOne, &playerTwo);
	}

	printf("\n\n------------- game over ---------------\n");
	if (playerOne.size == DECK_SIZE) {
		printf("Player one won !!\n");
	}	
	if (playerTwo.size == DECK_SIZE) {
		printf("Player two won !!\n");
	}
	return 0;
}