#include "../../headers.h"

class Solution
{   
public:
    int tallestBillboard(vector<int> &v)
    {
        unordered_map<int, int> dp;
        dp[0] = 0;
        for (int x : v)
        {
            unordered_map<int, int> mp(dp);
            for (auto [d, c] : mp)
            {
                dp[d + x] = max(dp[d + x], c);
                dp[abs(d - x)] = max(dp[abs(d - x)], c + min(d, x));
            }
        }
        return dp[0];
    }
};