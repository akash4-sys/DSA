#include "../../headers.h"

// Time Complexity - O(N^2)
// Space Complexity - O(N)

class Solution
{
public:
    int bestTeamScore(vector<int> &sc, vector<int> &a)
    {
        vector<pair<int, int>> v(a.size());
        for (int i = 0; i < sc.size(); i++)
            v[i] = {a[i], sc[i]};
        sort(v.begin(), v.end());

        int ans = 0;
        vector<int> dp(a.size(), 0);
        for (int i = 0; i < v.size(); i++)
        {
            dp[i] = v[i].second;
            for (int j = 0; j < i; j++)
                if (v[i].second >= v[j].second)
                    dp[i] = max(dp[i], v[i].second + dp[j]);
            ans = max(ans, dp[i]);
        }
        return ans; 
    }
};


// Time Complexity - O(N^2)
// Space Complexity - O(N^2)

class Solution
{
    int sumLIS(vector<pair<int, int>> &v, vector<vector<int>> &dp, int i, int prev)
    {
        if (i == v.size())
            return 0;
        if (dp[i][prev + 1] != -1)
            return dp[i][prev + 1];
        if (prev == -1 || v[i].second >= v[prev].second)
            dp[i][prev + 1] = sumLIS(v, dp, i + 1, i) + v[i].second;
        return dp[i][prev + 1] = max(dp[i][prev + 1], sumLIS(v, dp, i + 1, prev));
    }

public:
    int bestTeamScore(vector<int> &sc, vector<int> &a)
    {
        vector<pair<int, int>> v(a.size());
        vector<vector<int>> dp(a.size(), vector<int>(a.size(), -1));
        for (int i = 0; i < sc.size(); i++)
            v[i] = {a[i], sc[i]};

        sort(v.begin(), v.end());
        return sumLIS(v, dp, 0, -1);
    }
};

class Solution
{
    int sumLIS(vector<pair<int, int>> &v, int i, int prev, int sum)
    {
        if (i == v.size())
            return sum;
        int inc = 0;
        if (v[i].second >= prev)
            inc = sumLIS(v, i + 1, v[i].second, sum + v[i].second);
        return max(inc, sumLIS(v, i + 1, prev, sum));
    }

public:
    int bestTeamScore(vector<int> &sc, vector<int> &a)
    {
        vector<pair<int, int>> v(a.size());
        for (int i = 0; i < sc.size(); i++)
            v[i] = {a[i], sc[i]};
        sort(v.begin(), v.end());
        return sumLIS(v, 0, -1, 0);
    }
};

// @lc app=leetcode id=1626 lang=cpp