#include "headers.h"

// Binary Exponentiation
class Solution
{
public:
    int monkeyMove(int n)
    {
        long ans = 1, base = 2, mod = (long)1e9 + 7;
        for (; n; n /= 2)
        {
            if (n % 2 == 1)
                ans = (ans * base) % mod;
            base = (base * base) % mod;
        }
        return (ans - 2 + mod) % mod;
    }
};

// return pow(2, n) - 2;   (int exceeds)