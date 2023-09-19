/**
 * @author  Quickgrid ( Asif Ahmed )
 * @link    https://quickgrid.wordpress.com
 * Problem: UVA 357 – Let Me Count The Ways Solution
 */

#include <stdio.h>
#define N 30002

static long long a[N];
static const long long coins[4] = {5, 10, 25, 50};

int main()
{
    register unsigned long long i, j;
    long long n;

    for (i = 0; i < N; ++i)
        a[i] = 1;

    for (i = 0; i < 4; ++i)
    {
        for (j = coins[i]; j < N; ++j)
            a[j] += a[j - coins[i]];
    }

    while (scanf("%lld", &n) == 1)
    {
        if (a[n] == 1)
            printf("There is only %lld way to produce %lld cents change.\n", a[n], n);
        else
            printf("There are %lld ways to produce %lld cents change.\n", a[n], n);
    }
    return 0;
}