#include <stdio.h>
#include "../../header/structs/structs.h"
#include "../../header/funcs/funcs.h"


/**
 *	playTurn play a turn of battle game. Each player draw card, either one of them win,
 *	either it's the battle.
 */
void playTurn(deck* playerOne, deck* playerTwo) {
	if (playerOne->cards[0].height == playerTwo->cards[0].height) {
		battle(playerOne, playerTwo, 3);
	} else {
		printCard(playerOne->cards[0].value, playerOne->cards[0].color);
		printf(" --X-- ");
		printCard(playerTwo->cards[0].value, playerTwo->cards[0].color);
		printf("\n");

		if (playerOne->cards[0].height > playerTwo->cards[0].height) {
			addCard(playerOne, playerTwo->cards[0]);
			retrieveCard(playerTwo);	
		} else {
			addCard(playerTwo, playerOne->cards[0]);
			retrieveCard(playerOne);
		}
	}
}

/**
 * retrieveCard retrieve the played card of the player hand's
 * and shift up all the remain card.
 */
void retrieveCard(deck* player) {
	for (int i=1; i<=player->size; i++) {
		player->cards[i-1] = player->cards[i];
	}
	player->size -= 1;
}

/**
 * addCard add a card to the player hand's and  
 * put the played card and the won card to the bottom of the hand.
 */
void addCard(deck* player, card c) {
	card playedCard = player->cards[0];
	for (int i=1; i<=player->size; i++) {
		player->cards[i-1] = player->cards[i];
	}
	player->cards[player->size-1] = playedCard;
	player->cards[player->size] = c;
	player->size += 1;
}

/**
 * battle emulate a battle when two played card of the players have the same values.
 *
 */
void battle(deck* playerOne, deck* playerTwo, int pileSize) {
	printf("\n\n------------- battle !! ---------------\n\n");
	if (playerOne->cards[pileSize].height == playerTwo->cards[pileSize].height) {
		battle(playerOne, playerTwo, pileSize+1);
	} else {
		int i=0;
		deck piles[2][DECK_SIZE];
		
		for (int i=0; i<pileSize; i++) {
			piles[0]->cards[i] = playerOne->cards[i];
			piles[1]->cards[i] = playerTwo->cards[i];
		}
		
		printHands(piles[0], piles[1], pileSize);

		if (piles[0]->cards[pileSize-1].height > piles[1]->cards[pileSize-1].height) {
			for (int j = 0; j < pileSize; j++) {
				addCard(playerOne, playerTwo->cards[0]);
				retrieveCard(playerTwo);
			}
		} else {
			for (int j = 0; j < pileSize; j++) {
				addCard(playerTwo, playerOne->cards[0]);
				retrieveCard(playerOne);
			}
		}
		printf("\n----- this one has been rough ---------\n\n");
	}
}

/**
 * itsWon return true when one of player hand size is equal to 52.
 *
 */
bool itsWon(deck playerOne, deck playerTwo){
	return playerOne.size == DECK_SIZE || playerTwo.size == DECK_SIZE;
}