#include "../../headers.h"

class Solution
{
    int dp[1001][1001];
    int rec(vector<int> &v, int i, int k)
    {
        if (i == v.size())
            return 0;
        if (dp[i][k] != -1)
            return dp[i][k];
        
        int ans = INT_MAX;
        if (k) ans = rec(v, i + 1, k - 1);
        return dp[i][k] = min(ans, rec(v, i + 1, i + 1) + v[i]);
    }

public:
    int minimumCoins(vector<int> &v)
    {
        memset(dp, -1, sizeof(dp));
        return rec(v, 0, 0);
    }
};