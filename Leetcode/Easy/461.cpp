#include "../../headers.h"

// Time Complexity O(N) - O(32) - O(1)
class Solution
{
public:
    int hammingDistance(int x, int y)
    {
        return __builtin_popcount(x ^ y);
    }
};

class Solution 
{
public:
    int hammingDistance(int x, int y) 
    {
        return __builtin_popcount(x ^ y);
    }
};