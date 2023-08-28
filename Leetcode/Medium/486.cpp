#include "../../headers.h"

class Solution
{
public:
    bool PredictTheWinner(vector<int> &v)
    {
        int n = v.size();
        vector dp(n, vector<int>(n, 0));
        for (int i = 0; i < n; i++)
            dp[i][i] = v[i];

        for (int d = 1; d < n; d++)
            for (int l = 0; l < n - d; l++)
            {
                int r = l + d;
                dp[l][r] = max(v[l] - dp[l + 1][r], v[r] - dp[l][r - 1]);
            }
        return dp[0][n - 1] >= 0;
    }
};


class Solution
{
    int dp[20][20];
    int rec(vector<int> &v, int l, int r)
    {
        if (l > r)
            return 0;
        if (dp[l][r] != -1)
            return dp[l][r];

        int first = v[l] - rec(v, l + 1, r);
        int last = v[r] - rec(v, l, r - 1);
        return dp[l][r] = max(first, last);
    }

public:
    bool PredictTheWinner(vector<int> &v)
    {
        memset(dp, -1, sizeof(dp));
        return rec(v, 0, v.size() - 1) >= 0;
    }
};


// works even without t state

class Solution
{
    int dp[20][20][2];
    int rec(vector<int> &v, int l, int r, int t)
    {
        if (l > r)
            return 0;
        if (dp[l][r][t] != -1)
            return dp[l][r][t];

        int sign = t ? 1 : -1;
        int first = rec(v, l + 1, r, !t) + (v[l] * sign);
        int last = rec(v, l, r - 1, !t) + (v[r] * sign);
        return dp[l][r][t] = t ? max(first, last) : min(first, last);
    }

public:
    bool PredictTheWinner(vector<int> &v)
    {
        memset(dp, -1, sizeof(dp));
        return rec(v, 0, v.size() - 1, 1) >= 0;
    }
};

// @lc app=leetcode id=486 lang=cpp