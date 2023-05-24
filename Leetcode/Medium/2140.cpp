#include "../../headers.h"

class Solution
{
public:
    long long mostPoints(vector<vector<int>> &v)
    {
        vector<long long> dp(v.size() + 1, 0);
        for (int i = v.size() - 1; i >= 0; i--)
            dp[i] = max(dp[i + v[i][1] + 1] + v[i][0], dp[i + 1]);
        return dp[0];
    }
};


class Solution
{
    long long rec(vector<vector<int>> &v, vector<long long> &dp, int i)
    {
        if (i >= v.size())
            return 0;
        if (dp[i] != -1)
            return dp[i];
        return dp[i] = max(rec(v, dp, i + v[i][1] + 1) + v[i][0], rec(v, dp, i + 1));
    }

public:
    long long mostPoints(vector<vector<int>> &v)
    {
        vector<long long> dp (v.size(), -1);
        return rec(v, dp, 0);
    }
};