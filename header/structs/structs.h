#ifndef STRUCTS
#define STRUCTS

#define MAX_STR_SIZE 8
#define DECK_SIZE 52
#define NB_COLORS 4
#define NB_VALUES 13

extern char colors[NB_COLORS][MAX_STR_SIZE]; 
extern char values[NB_VALUES][MAX_STR_SIZE]; 

/**
 * card is composed of a color and a value. Height is the an extra field to help
 * the comparison between two cards.   
 */
typedef struct{
	char color[MAX_STR_SIZE];
	char value[MAX_STR_SIZE];
	int height;
}card;

/**
 * deck is an array of card with a given size. The size field is the current deck size. It evolve often.
 *
 */
typedef struct{
	int size;
	card cards[DECK_SIZE];
}deck;

#endif