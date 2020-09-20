#ifndef FUNCS
#define FUNCS

#include <stdbool.h>

void fillDeck(deck*);
void printDeck(deck*);
void printCard(char[], char[]);
void fillCard(card*, char[], char[], int height);
deck shuffleDeck(deck*);
int getRandomInt(int[], int);
bool randIsAlreadyTaken(int[], int, int);
void dealCards(deck*,deck*,deck*);
void printHands(deck*,deck*, int);
void retrieveCard(deck*);
void addCard(deck*, card);
void battle(deck*, deck*, int pileSize);
void playTurn(deck*, deck*);
bool itsWon(deck, deck);

#endif