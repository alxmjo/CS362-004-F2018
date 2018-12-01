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
int testGetWinners();

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
    testGetWinners();

    // Free malloc'd state
    free(state);
}

int testGetWinners()
{
    int players[MAX_PLAYERS];
    
    getWinners(players, state);
    if (players[0] == 1) // Winner
    {
        printf("getWinners(testing winner): Passed!\n");
    }
    else
    {
        printf("getWinners(testing winner): Failed!\n");
    }
    if (players[1] == 0) // Loser
    {
        printf("scoreFor(testing loser): Passed!\n");
    }
    else
    {
        printf("scoreFor(testing loser): Failed!\n");
    }

    return 0;
}
