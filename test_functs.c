/*
 * File:      test_functs.c
 * Author:    Michael Sanford 100113669
 * Date:      14/11/2013
 * Version:   1.0
 *
 * Purpose:
 */

#include <inttypes.h>
#include <math.h>

#define CACHE_SIZE 4

/*
 *
 */

int is_a_prime(uint64_t x)
{
    static int history_vals[CACHE_SIZE] = {0};
    static int history_returns[CACHE_SIZE] = {0};
    int temp_vals, temp_returns, is_cached, is_true;
    is_cached = -1;
    is_true = -1;
    for (int i = 0; i < CACHE_SIZE; i++)
    {
        if (x == history_vals[i])
            is_cached = i;
        else
            is_cached = -1;
    }
    if (is_cached != -1)
    {
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
        uint64_t y = sqrt(x);
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
    }
    return is_true;
}

/*
 *
 */

int is_a_perfect_square(uint64_t x)
{
    int is_true = 0;
    for (int i = 1; i * i <= x; i++)
    {
        if (i * i == x)
            is_true = 1;
    }
    return is_true;
}

/*
 *
 */

int is_a_perfect_cude(int64_t x)
{
    int is_true = 0;
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
