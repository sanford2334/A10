/*
 * File:      a10p1.c
 * Author:    Michael Sanford 100113669
 * Date:      14/11/2013
 * Version:   1.0
 *
 * Purpose:
 */

#include <stdio.h>
#include <stdlib.h>
#include <inttypes.h>
#include <math.h>
#include <time.h>

/*
 * Name:      fast_Power
 * Purpose:
 * Arguments:
 * Returns:
 */

uint64_t fast_Power(uint64_t k, uint64_t n, uint32_t m)
{
    uint64_t i = 0;
    if (n > 1)
    {
        if ((n % 2) == 0)
        {
            i = fast_Power(k, n / 2, m);
            return i * i % m;
        }
        else
            return k * fast_Power(k, n - 1, m) % m;
    }
    else if (n == 1)
        return k;
    return 1;
}

/*
 * Name:      normal_Power
 * Purpose:
 * Arguments:
 * Returns:
 */

uint64_t normal_Power(uint64_t k, uint64_t n, uint32_t m)
{
    uint64_t p = 1;
    for (uint64_t i = 0; i < n; i++)
        p = p * k % m;
    return p;
}

int main(int argc, char * argv[])
{
    struct timespec start_time, end_time, total_fast, total_iter;
    double t_fast, t_iter;
    uint32_t m_in;
    uint64_t k_in, catch_fast, catch_iter;
    if (argc != 3)
    {
        fprintf(stderr, "Error: Invalid Number of Inputs!");
        return EXIT_FAILURE;
    }
    if (argv[1] < argv[2])
    {
        sscanf(argv[1], "%" SCNu64, &k_in);
        sscanf(argv[2], "%" SCNu32, &m_in);
    }
    else
    {
        sscanf(argv[1], "%" SCNu32, &m_in);
        sscanf(argv[2], "%" SCNu64, &k_in);
    }
    for (int i = 0; i <= 10; i++)
    {
        clock_gettime(CLOCK_REALTIME, &start_time);
        catch_fast = fast_Power(k_in, pow(10, i), m_in);
        clock_gettime(CLOCK_REALTIME, &end_time);
        total_fast.tv_sec = end_time.tv_sec - start_time.tv_sec;
        total_fast.tv_nsec = end_time.tv_nsec - start_time.tv_nsec;

        clock_gettime(CLOCK_REALTIME, &start_time);
        catch_iter = normal_Power(k_in, pow(10, i), m_in);
        clock_gettime(CLOCK_REALTIME, &end_time);
        total_iter.tv_sec = end_time.tv_sec - start_time.tv_sec;
        total_iter.tv_nsec = end_time.tv_nsec - start_time.tv_nsec;

        t_fast = total_fast.tv_sec + total_fast.tv_nsec / 1000000000.0;
        t_iter = total_iter.tv_sec + total_iter.tv_nsec / 1000000000.0;

        printf("%" PRIu64 "\n", catch_fast);
        printf("%" PRIu64 "\n", catch_iter);
        printf("%g\n", t_fast);
        printf("%g\n", t_iter);
    }
    return EXIT_SUCCESS;
}
