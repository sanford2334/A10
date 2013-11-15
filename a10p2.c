/*
 * File:      a10p2.c
 * Author:    Michael Sanford 100113669
 * Date:      14/11/2013
 * Version:   1.0
 *
 * Purpose:
 */

#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <inttypes.h>
#include "test_functs.h"

int main(int argc, char * argv[])
{
    char c = '\0';
    int64_t x = 0;
    int catcher = 0;
    while (1)
    {
        printf("\nPlease enter a number: ");
        scanf("%" SCNi64, &x);
        while ((c = getchar()) != '\n')
            ;
        catcher = is_a_prime(x);
        if (catcher == 1)
            printf("%" PRIi64 " is a prime number!\n", x);
        else
            printf("%" PRIi64 " is not a prime number.\n", x);
        catcher = is_a_perfect_square(x);
        if (catcher == 1)
            printf("%" PRIi64 " is a perfect square!\n", x);
        else
            printf("%" PRIi64 " is not a perfect square.\n", x);
        catcher = is_a_perfect_cube(x);
        if (catcher == 1)
            printf("%" PRIi64 " is a perfect cube!\n", x);
        else
            printf("%" PRIi64 " is not a perfect cube.\n", x);
        printf("Would you like to test another number? y/n ");
        c = getchar();
        if (c != 'y')
            break;
    }
    int count = 0;
    printf("Mersenne primes:\n");
    while (count != 8)
    {
        for (int i = 1; i > 0; i++)
        {
            catcher = is_a_prime(pow(2, i) - 1);
            if (catcher == 1)
            {
                count++;
                printf("%d is a Mersenne prime.\n", (int)pow(2, i) - 1);
            }
            if (count == 8)
                break;
        }
    }
    return EXIT_SUCCESS;
}
