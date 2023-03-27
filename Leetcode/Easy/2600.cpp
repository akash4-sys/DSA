#include "headers.h"

class Solution
{
public:
    int kItemsWithMaximumSum(int o, int z, int n, int k)
    {
        int x = o + z;
        return k - x <= 0 ? min(o, k) : o - min(k - x, n);
    }
};