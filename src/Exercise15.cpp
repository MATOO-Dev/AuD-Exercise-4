#include "../include/Exercise15.h"

int Exercise15::T_r(int n)
{
    if(n == 1)
        return 1;
    return n * T_r(n - 1) + n;
}

int Exercise15::T_i(int n)
{
    int results[n+1];
    results[1] = 1;

    if(n == 1)
        return results[n];

    for(int i = 2; i <= n; i++)
    {
        results[i] = i * results[i-1] + i;
    }
    return results[n];
}