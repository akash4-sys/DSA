#include "../../headers.h"

class Solution
{
public:
    int hammingWeight(uint32_t n)
    {
        // return __builtin_popcount(n);
        int c = 0;
        while(n)
            ++c, n &= (n - 1);
        return c;
    }
};