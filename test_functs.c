/*
 * File:      test_functs.c
 * Author:    Michael Sanford 100113669
 * Date:      14/11/2013
 * Version:   1.0
 *
 * Purpose:   to test the entered number to see if it is prime, a perfect
 *            square, or a perfect cube
 */

#include <inttypes.h>
#include <math.h>
#include <stdio.h>

#define CACHE_SIZE 4

/*
 * Name:      is_a_prime
 * Purpose:   check if the number is a prime number
 * Arguments: uint64_t of entered number
 * Returns:   1 if true, other wise 0
 */

int is_a_prime(uint64_t x)
{
    static int history_vals[CACHE_SIZE] = {0};
    static int history_returns[CACHE_SIZE] = {0};
    int temp_vals, temp_returns, is_cached, is_true;
    is_cached = -1;
    is_true = 0;
    for (int i = 0; i < CACHE_SIZE; i++)
    {
        if (x == history_vals[i])
            is_cached = i;
        else
            is_cached = -1;
    }
    if (is_cached != -1)
    {
#ifdef DEBUG
        printf("We are in the cache!\n");
#endif
        temp_vals = history_vals[is_cached];
        temp_returns = history_returns[is_cached];
        for (int k = is_cached; k < CACHE_SIZE - 1; k++)
        {
            history_vals[k] = history_vals[k + 1];
            history_returns[k] = history_returns[k + 1];
        }
        history_vals[CACHE_SIZE - 1] = temp_vals;
        history_returns[CACHE_SIZE - 1] = temp_returns;
        is_true = 1;
    }
    else
    {
        uint64_t y = rint(sqrt(x));
        for (uint64_t j = 2; j <= y; j++)
        {
            if ((x % j) != 0)
                is_true = 1;
            else
            {
                is_true = 0;
                break;
            }
        }
        for (int k = is_cached; k < CACHE_SIZE - 1; k++)
        {
            history_vals[k] = history_vals[k + 1];
            history_returns[k] = history_returns[k + 1];
        }
        history_vals[CACHE_SIZE - 1] = x;
        history_returns[CACHE_SIZE - 1] = is_true;
    }
    return is_true;
}

/*
 * Name:      is_a_perfect_square
 * Purpose:   to check if the entered number is a perfect square
 * Arguments: uint64_t of number entered
 * Returns:   1 if true, other wise 0
 */

int is_a_perfect_square(uint64_t x)
{
    static int history_vals[CACHE_SIZE] = {0};
    static int history_returns[CACHE_SIZE] = {0};
    int temp_vals, temp_returns, is_cached, is_true;
    is_cached = -1;
    is_true = 0;
    for (int i = 0; i < CACHE_SIZE; i++)
    {
        if (x == history_vals[i])
            is_cached = i;
        else
            is_cached = -1;
    }
    if (is_cached != -1)
    {
#ifdef DEBUG
        printf("We are in the cache!\n");
#endif
        temp_vals = history_vals[is_cached];
        temp_returns = history_returns[is_cached];
        for (int k = is_cached; k < CACHE_SIZE - 1; k++)
        {
            history_vals[k] = history_vals[k + 1];
            history_returns[k] = history_returns[k + 1];
        }
        history_vals[CACHE_SIZE - 1] = temp_vals;
        history_returns[CACHE_SIZE - 1] = temp_returns;
        is_true = 1;
    }
    for (int i = 1; i * i <= x; i++)
    {
        if (i * i == x)
            is_true = 1;
    }
    return is_true;
}

/*
 * Name:      is_a_perfect_cube
 * Purpose:   to check if the entered number is a perfect cube
 * Arguments: int64_t of number entered, because it can also be a negative
 *            number
 * Returns:   1 if true, other wise 0
 */

int is_a_perfect_cube(int64_t x)
{
    static int history_vals[CACHE_SIZE] = {0};
    static int history_returns[CACHE_SIZE] = {0};
    int temp_vals, temp_returns, is_cached, is_true;
    is_cached = -1;
    is_true = 0;
    for (int i = 0; i < CACHE_SIZE; i++)
    {
        if (x == history_vals[i])
            is_cached = i;
        else
            is_cached = -1;
    }
    if (is_cached != -1)
    {
#ifdef DEBUG
        printf("We are in the cache!\n");
#endif
        temp_vals = history_vals[is_cached];
        temp_returns = history_returns[is_cached];
        for (int k = is_cached; k < CACHE_SIZE - 1; k++)
        {
            history_vals[k] = history_vals[k + 1];
            history_returns[k] = history_returns[k + 1];
        }
        history_vals[CACHE_SIZE - 1] = temp_vals;
        history_returns[CACHE_SIZE - 1] = temp_returns;
        is_true = 1;
    }
    if (x > 0)
    {
        for (int i = 1; i * i * i <= x; i++)
        {
            if (i * i * i == x)
                is_true = 1;
        }
    }
    else if (x < 0)
    {
        for (int j = -1; j * j * j >= x; j--)
        {
            if (j * j * j == x)
                is_true = 1;
        }
    }
    return is_true;
}
