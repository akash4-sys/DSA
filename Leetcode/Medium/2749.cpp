#include "../../headers.h"

class Solution
{
public:
    int makeTheIntegerZero(long x, long y)
    {
        for (int n = 1; n <= 60; n++)
            if (__builtin_popcountll(x - (n * y)) <= n && n <= x - (n * y))
                return n;
        return -1;
    }
};