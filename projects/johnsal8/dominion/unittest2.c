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
int testScoreFor();

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
    testScoreFor();

    // Free malloc'd state
    free(state);
}

int testScoreFor()
{
    int score0 = scoreFor(0, state);
    if (score0 == 0) // No turns played, score should be 0
    {
        printf("scoreFor(player 0): Passed!\n");
    }
    else
    {
        printf("scoreFor(player 0): Failed!\n");
    }

    int score1 = scoreFor(1, state);
    if (score1 == 0) // No turns played, score should be 0
    {
        printf("scoreFor(player 1): Passed!\n");
    }
    else
    {
        printf("scoreFor(player 1): Failed!\n");
    }

    return 0;
}
