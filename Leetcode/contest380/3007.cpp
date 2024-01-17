#include "../../headers.h"

class Solution
{
    long long setBitCount(long long n, long long x)
    {
        long long cost = 0;
        for (int colIdx = 64 - __builtin_clzll(n - 1); colIdx; colIdx--)
            if (colIdx % x == 0)
            {
                long long grps = n / (1LL << colIdx);
                long long ones = 1LL << (colIdx - 1);
                long long leftOnes = max((n % (1LL << colIdx)) - ones, 0LL);
                cost += (grps * ones) + leftOnes;
            }
        return cost;
    }

public:
    long long findMaximumNumber(long long k, int x)
    {
        long long l = 1, r = 1e15;
        while (l <= r)
        {
            long long mid = (r - l) / 2 + l;
            setBitCount(mid + 1, x) <= k ? l = mid + 1 : r = mid - 1;
        }
        return l - 1;
    }
};