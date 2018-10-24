#include <limits.h>
#include <stdio.h>
#include <stdlib.h>
#include "dominion.h"

// Typedefs
typedef enum
{
	false,
	true
} bool;

// Prototypes
int testGreat_Hall();

// Globals
struct gameState *state;

int main()
{
    // Mock a game
    int players = 2;
    int k[10] = { great_hall, embargo, great_hall, outpost, mine, cutpurse, sea_hag, great_hall, smithy, council_room };
    int randomSeed = rand();
    state = malloc(sizeof(struct gameState));
    initializeGame(players, k, randomSeed, state);

    // Run test
    testGreat_Hall();

    // Free malloc'd state
    free(state);
}

int testGreat_Hall()
{
    int choice1 = 0;
    int choice2 = 0;
    int choice3 = 0;
    int handPos = 0;
    int bonus = 0;
    
    
    cardEffect(great_hall, choice1, choice2, choice3, state, handPos, &bonus);
    if (state->playedCardCount == 1) // counts as played card
    {
        printf("great_hall(played card count): Passed!\n");
    }
    else
    {
        printf("great_hall(played card count): Failed!\n");
    }
    if (state->numActions == 1) // card will add one to numActions
    {
        printf("great_hall(numActions == 2): Passed!\n");
    }
    else
    {
        printf("great_hall(numActions == 2): Failed!\n");
    }

    return 0;
}
