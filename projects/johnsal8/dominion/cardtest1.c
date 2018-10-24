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
int testSmithy();

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
    testSmithy();

    // Free malloc'd state
    free(state);
}

int testSmithy()
{
    int choice1 = 0;
    int choice2 = 0;
    int choice3 = 0;
    int handPos = 0;
    int bonus = 0;
    
    cardEffect(smithy, choice1, choice2, choice3, state, handPos, &bonus);
    if (state->playedCardCount == 1)
    {
        printf("smithy(played card count): Passed!\n");
    }
    else
    {
        printf("smithy(played card count): Failed!\n");
    }
    if (state->handCount[0] == 7) // Started with 5, played 1, gained 3 --> 7
    {
        printf("smithy(hand count): Passed!\n");
    }
    else
    {
        printf("smithy(hand count): Failed!\n");
    }

    return 0;
}
