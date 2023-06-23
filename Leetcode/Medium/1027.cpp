#include "../../headers.h"

class Solution
{
public:
    int longestArithSeqLength(vector<int> &v)
    {
        int ans = 2, n = v.size();
        vector dp(n, vector<int>(2000, 0));
        for (int i = 0; i < n; i++)
            for (int j = i + 1; j < n; j++)
            {
                int d = v[j] - v[i] + 1000;
                dp[j][d] = max(dp[i][d] + 1, 2);
                ans = max(ans, dp[j][d]);
            }
        return ans;
    }
};