#include "../../headers.h"

// Time Complexity - O(1)
class Solution
{
public:
    int bitwiseComplement(int n)
    {
        if(!n)
            return 1;
        int numOfSetBits = (int)log2(n) + 1;
        return n ^ ((1 << numOfSetBits) - 1);
    }
};

// Time Complexity - O(N) - O(32)
class Solution
{
public:
    int bitwiseComplement(int n)
    {
        int x = 1;
        while(n > x)
            x = (x * 2) + 1;
        // return x - n;
        return x ^ n;
    }
};