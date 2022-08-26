#include "../../headers.h"

class Solution
{
public:
    int dfs(vector<int> &v, int d, vector<int> &dp, int i, int ans = 1)
    {
        if(dp[i])
            return dp[i];
        for(int j = i + 1; j <= min(i + d, (int)v.size()-1) && v[j] < v[i]; j++)
            ans = max(ans, 1 + dfs(v, d, dp, j));
        for(int j = i - 1; j >= max(i - d, 0) && v[j] < v[i]; j--)
            ans = max(ans, 1 + dfs(v, d, dp, j));
        return dp[i] = ans;
    }

    int maxJumps(vector<int> &v, int d)
    {
        int ans = 1;
        vector<int> dp(v.size());
        for (int i = 0; i < v.size(); i++)
            ans = max(ans, dfs(v, d, dp, i));
        return ans;
    }
};