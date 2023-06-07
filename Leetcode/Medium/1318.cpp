#include "../../headers.h"

class Solution
{
public:
    int minFlips(int a, int b, int c)
    {
        return __builtin_popcount((a | b) ^ c) + 
            __builtin_popcount(a & b & ((a | b) ^ c));
    }
};


class Solution
{
public:
    int minFlips(int a, int b, int c)
    {
        int ans = 0;
        for (int i = 0; i < 32; i++)
        {
            int p = 1 << i, x = a & p, y = b & p, z = c & p;
            ans += (x && !y && !z);
            ans += (!x && y && !z);
            ans += (!x && !y && z);
            ans += (x && y && !z) ? 2 : 0;
        }
        return ans;
    }
};