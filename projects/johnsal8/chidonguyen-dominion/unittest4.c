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
int testIsGameOver();

// Globals
struct gameState *state;

int main()
{
    // Mock a game
    int players = 2;
    int k[10] = { adventurer, embargo, village, outpost, mine, cutpurse, sea_hag, great_hall, smithy, council_room };
    int randomSeed = rand();
    state = malloc(sizeof(struct gameState));
    initializeGame(players, k, randomSeed, state);

    // Run test
    testIsGameOver();

    // Free malloc'd state
    free(state);
}

int testIsGameOver()
{   
    if (isGameOver(state) == 0)
    {
        printf("isGameOver(no): Passed!\n");
    }
    else
    {
        printf("isGameOver(no): Failed!\n");
    }
    
    state->supplyCount[province] = 0; // update state to force game over
    if (isGameOver(state) == 1)
    {
        printf("isGameOver(yes): Passed!\n");
    }
    else
    {
        printf("isGameOver(yes): Failed!\n");
    }

    return 0;
}
