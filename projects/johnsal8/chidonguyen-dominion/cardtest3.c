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
int testVillage();

// Globals
struct gameState *state;

int main()
{
    // Mock a game
    int players = 2;
    int k[10] = { village, embargo, village, outpost, mine, cutpurse, sea_hag, great_hall, smithy, council_room };
    int randomSeed = rand();
    state = malloc(sizeof(struct gameState));
    initializeGame(players, k, randomSeed, state);

    // Run test
    testVillage();

    // Free malloc'd state
    free(state);
}

int testVillage()
{
    int choice1 = 0;
    int choice2 = 0;
    int choice3 = 0;
    int handPos = 0;
    int bonus = 0;
    
    
    cardEffect(village, choice1, choice2, choice3, state, handPos, &bonus);
    if (state->playedCardCount == 1) // counts as played card
    {
        printf("village(played card count): Passed!\n");
    }
    else
    {
        printf("village(played card count): Failed!\n");
    }
    if (state->numActions == 2) // card will add two to numActions
    {
        printf("village(numActions == 2): Passed!\n");
    }
    else
    {
        printf("village(numActions == 2): Failed!\n");
    }

    return 0;
}
