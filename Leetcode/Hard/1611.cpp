#include "../../headers.h"

// Time Complexity - O(logN)
// Space Compelxity - O(1)

class Solution
{
public:
    int minimumOneBitOperations(int n)
    {
        int ans = 0;
        for (; n; n >>= 1)
            ans ^= n;
        return ans;
    }
};


// Time Complexity - O(logN)
// Space Compelxity - O(logN)

class Solution
{
public:
    int minimumOneBitOperations(int n)
    {
        if (!n)
            return 0;
        int k = 32 - __builtin_clz(n);
        return (1 << k) - minimumOneBitOperations(n ^ (1 << (k - 1))) - 1;
    }
};