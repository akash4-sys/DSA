#include "../../headers.h"

class Solution
{
public:
    int maximumXorProduct(long long a, long long b, int n)
    {
        long long mod = 1e9 + 7;
        for (long long i = n - 1; i >= 0; i--)
        {
            long long bit = 1LL << i;
            if ((a & bit) == (b & bit))
                a |= bit, b |= bit;
            else
            {
                if (a > b)
                    swap(a, b);
                a |= bit;
                b &= (~bit);
            }
        }
        return ((a % mod) * (b % mod)) % mod;
    }
};