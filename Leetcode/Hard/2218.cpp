#include "../../headers.h"

class Solution
{
    vector<vector<int>> dp;
    int rec(vector<vector<int>> &v, int i, int k)
    {
        if (!k || i == v.size())
            return 0;
        if (dp[i][k] != -1)
            return dp[i][k];
        for (int j = -1; j < min(k, (int)v[i].size()); j++)
        {
            int x = rec(v, i + 1, k - j - 1) + (j > -1 ? v[i][j] : 0);
            dp[i][k] = max(dp[i][k], x);
        }
        return dp[i][k];
    }

public:
    int maxValueOfCoins(vector<vector<int>> &v, int k)
    {
        dp = vector(v.size(), vector<int>(k + 1, -1));
        for (auto &r : v)
            partial_sum(r.begin(), r.end(), r.begin());
        return rec(v, 0, k);
    }
};