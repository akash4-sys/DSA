#include "../../headers.h"

class Solution
{
public:
    int countMaxOrSubsets(vector<int> &v)
    {
        int maxOR = 0, dp[1 << 17] = {1};
        for(int n: v)
        {
            for(int i = maxOR; i >= 0; --i)
                dp[i | n] += dp[i];
            maxOR |= n;
        }
        return dp[maxOR];
    }
};



// Time Complexity O(2^N * N)
// Space Complexity - O(1)
class Solution
{
public:
    int countMaxOrSubsets(vector<int> &v)
    {
        int ans = 0, maxOR = 0;
        for (int i = 1; i < (1 << v.size()); i++)
        {
            int x = 0;
            for (int j = 0; j < v.size(); j++)
                if (i & (1 << j))
                    x |= v[j];

            ans += maxOR == x;
            if (maxOR < x)
                maxOR = x, ans = 1;
        }
        return ans;
    }
};