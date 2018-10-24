#include <limits.h>
#include <stdio.h>
#include "dominion.h"

// Typedefs
typedef enum
{
	false,
	true
} bool;

// Prototypes
int testCompare();

int main()
{
    testCompare();
}

int testCompare()
{
    int min = INT_MIN;
    int max = INT_MAX;
    int result;
    
    result = compare(&min, &max);
    if (result == -1)
    {
        printf("compare(INT_MIN, INT_MAX): Passed!\n");
    }
    else
    {
        printf("compare(INT_MIN, INT_MAX): Failed!\n");
    }

    result = compare(&max, &min);
    if (result == 1)
    {
        printf("compare(INT_MAX, INT_MAX): Passed!\n");
    }
    else
    {
        printf("compare(INT_MAX, INT_MAX): Failed!\n");
    }

    result = compare(&min, &min);
    if (result == 0)
    {
        printf("compare(INT_MIN, INT_MIN): Passed!\n");
    }
    else
    {
        printf("compare(INT_MIN, INT_MIN): Failed!\n");
    }

    return 0;
}
