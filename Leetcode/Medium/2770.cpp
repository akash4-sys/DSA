#include "../headers.h"

class Solution
{
public:
    int maximumJumps(vector<int> &v, int t)
    {
        vector<int> dp(v.size(), INT_MIN);
        dp.back() = 0;
        for (int i = v.size() - 2; i >= 0; i--)
            for (int j = i + 1; j < v.size(); j++)
                if (abs(v[j] - v[i]) <= t && dp[j] != INT_MIN)
                    dp[i] = max(dp[i], dp[j] + 1);
        return dp[0] == INT_MIN ? -1 : dp[0];
    }
};


class Solution
{
    int rec(vector<int> &v, vector<int> &dp, int t, int i)
    {
        if (i == v.size() - 1)
            return 0;
        if (dp[i] != INT_MIN)
            return dp[i];

        int res = -1;
        for (int j = i + 1; j < v.size(); j++)
            if (abs(v[j] - v[i]) <= t) {
                int steps = rec(v, dp, t, j);
                if (steps != -1)
                    res = max(res, steps + 1);
            }
        return dp[i] = res;
    }

public:
    int maximumJumps(vector<int> &v, int t)
    {
        vector<int> dp(v.size(), INT_MIN);
        return rec(v, dp, t, 0);
    }
};