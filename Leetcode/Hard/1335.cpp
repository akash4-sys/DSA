#include "../../headers.h"

class Solution
{
public:
    int minDifficulty(vector<int> &v, int D)
    {
        int n = v.size(), maxd;
        if (n < D)
            return -1;
        vector<int> dp(n + 1, INT_MAX);
        dp[n] = 0;
        for (int d = 1; d <= D; ++d)
            for (int i = 0; i <= n - d; ++i)
            {
                maxd = 0, dp[i] = INT_MAX;
                for (int j = i; j <= n - d; ++j)
                {
                    maxd = max(maxd, v[j]);
                    dp[i] = min(dp[i], maxd + dp[j + 1]);
                }
            }
        return dp[0];
    }
};



class Solution
{
public:
    int minDifficulty(vector<int> &v, int D)
    {
        int n = v.size(), maxD;
        if (n < D)
            return -1;
        vector<vector<int>> dp(D, vector<int>(v.size()));
        dp[0][0] = v[0];
        for (int i = 1; i < v.size(); i++)
            dp[0][i] = max(v[i], dp[0][i - 1]);

        for (int d = 1; d < d; ++d)
            for (int i = d; i < v.size(); ++i)
            {
                int currMax = v[i];
                dp[d][i] = INT_MAX;
                for (int j = i; j >= d; --j)
                {
                    currMax = max(currMax, v[j]);
                    dp[d][i] = min(dp[d][i], dp[d - 1][j - 1] + currMax);
                }
            }
        return dp[D - 1][v.size() - 1];
    }
};




// Something wrong somewhere hence not working

class Solution
{
    int dfs(vector<vector<int>> &dp, vector<int> &v, int i, int d)
    {
        if (d == 0 && i == v.size())
            return 0;
        if (d == 0 || i == v.size())
            return INT_MAX;
        if (dp[i][d] != -1)
            return dp[i][d];

        int curMax = v[i], m = INT_MAX;
        for (int j = i; j < v.size(); j++)
        {
            curMax = max(curMax, v[j]);
            int x = dfs(dp, v, j + 1, d - 1);
            if (x != INT_MAX)
                m = min(dp[i][d], curMax + x);
        }
        return dp[i][d] = m;
    }

public:
    int minDifficulty(vector<int> &v, int d)
    {
        if (v.size() < d)
            return -1;
        vector<vector<int>> dp(v.size(), vector<int>(d + 1, -1));
        return dfs(dp, v, 0, d);
    }
};



//  Recursive
class Solution
{
    int dfs(vector<int> &v, int i, int d)
    {
        if (d == 1)
            return *max_element(v.begin() + i, v.end());
        int ans = INT_MAX, curD = INT_MIN;
        for (int j = i; j <= v.size() - d; j++)
        {
            curD = max(curD, v[j]);
            ans = min(ans, dfs(v, j + 1, d - 1) + curD);
        }
        return ans;
    }

public:
    int minDifficulty(vector<int> &v, int d)
    {
        if (v.size() < d)
            return -1;
        return dfs(v, 0, d);
    }
};

// @lc app=leetcode id=1335 lang=cpp