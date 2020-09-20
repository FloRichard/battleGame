#include "../../header/structs/structs.h"
#include "../../header/funcs/funcs.h"

/**
 *	shuffleDeck will shuffle the deck in a new random deck.
 *
 */
deck shuffleDeck(deck* d){
	deck shuffledDeck;	
	int rands[DECK_SIZE];
	int randomInt;

	for (int i=0; i<DECK_SIZE; i++) {
		randomInt = getRandomInt(rands, i);
		shuffledDeck.cards[i] = d->cards[randomInt];
	}

	return shuffledDeck;
}

/**
 * dealCards deal deck to the two player.
 *
 */
void dealCards(deck* shuffledDeck,deck* playerOne, deck* playerTwo){
	playerOne->size = DECK_SIZE/2;
	playerTwo->size = DECK_SIZE/2;
	for (int i=0; i<DECK_SIZE; i++) {
		if (i < DECK_SIZE/2) {
			fillCard(&playerOne->cards[i], shuffledDeck->cards[i].value, shuffledDeck->cards[i].color, shuffledDeck->cards[i].height);
		} else {
			fillCard(&playerTwo->cards[i-DECK_SIZE/2], shuffledDeck->cards[i].value, shuffledDeck->cards[i].color, shuffledDeck->cards[i].height);	
		}
	}
}