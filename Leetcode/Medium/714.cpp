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
                    dp[i % 2][buy] = max(-fee - p[i] + dp[(i + 1) % 2][0], 0 + dp[(i + 1) % 2][buy]);
                else
                    dp[i % 2][buy] = max(p[i] + dp[(i + 1) % 2][1], 0 + dp[(i + 1) % 2][buy]);
        return dp[0][1];
    }
};