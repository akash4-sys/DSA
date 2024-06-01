#include "../../headers.h"

class Solution
{
public:
    int minOperations(int k)
    {
        int ans = k > 1 ? k : 0;
        for (int i = 1; i <= k; i++)
            ans = min(ans, (int)ceil(k / (i * 1.0)) - 2);
        return ans;
    }
};