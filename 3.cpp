#include "headers.h"

class Solution
{
    int mod = 1e9 + 7;
    int dfs(int t, vector<vector<int>> &v, vector<vector<int>> &dp, int i, int sum)
    {
        if (t == sum)
            return 1;
        if (sum > t || i == v.size())
            return 0;
        if (dp[i][sum] != -1)
            return dp[i][sum];
        
        int ans = 0;
        for (int j = 0, x = 0; j <= v[i][0]; j++, x += v[i][1])
            ans = (ans + dfs(t, v, dp, i + 1, sum + x)) % mod;
        return dp[i][sum] = ans;
    }

public:
    int waysToReachTarget(int t, vector<vector<int>> &v)
    {
        vector<vector<int>> dp(v.size(), vector<int>(t + 1, -1));
        return dfs(t, v, dp, 0, 0);
    }
};