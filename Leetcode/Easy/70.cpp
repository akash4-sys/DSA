#include "../../headers.h"

class Solution
{
public:
    int climbStairs(int n)
    {
        int ans = 1, last = 1, latest = 2;
        for(int i = 3; i <= n; i++)
        {
            ans = last + latest;
            last = latest;
            latest = ans;
        }
        return ans;
    }
};