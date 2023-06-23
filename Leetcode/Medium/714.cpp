#include "../../headers.h"

// Time Complexity - O(N)
// Space Complexity - O(1)

class Solution
{
public:
    int maxProfit(vector<int> &p, int fee)
    {
        vector<vector<int>> dp(2, vector<int>(2, 0));
        for(int i = p.size() - 1; i >= 0; i--)
            for(int buy = 0; buy <= 1; buy++)
                if(buy)
                    dp[i % 2][buy] = max(dp[(i + 1) % 2][0] - p[i] - fee, dp[(i + 1) % 2][1]);
                else
                    dp[i % 2][buy] = max(p[i] + dp[(i + 1) % 2][1], dp[(i + 1) % 2][0]);
        return dp[0][1];
    }
};