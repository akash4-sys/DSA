#include "../../headers.h"

class Solution
{
public:
    int eraseOverlapIntervals(vector<vector<int>> &v)
    {
        sort(v.begin(), v.end(), [&](auto &a, auto &b){
            return a[1] < b[1];
        });

        int p = INT_MIN, ans = 0;
        for (auto a : v)
            (a[0] < p) ? ans++ : p = a[1];
        return ans;
    }
};

// Time Complexity - O(NlogN)
// Space Complexity - O(N)

class Solution
{
    int bs(vector<vector<int>> &v, int l, int t)
    {
        for (int r = v.size(); l < r;)
        {
            int md = l + (r - l) / 2;
            (v[md][0] < t) ? l = md + 1 : r = md;
        }
        return l;
    }

public:
    int eraseOverlapIntervals(vector<vector<int>> &v)
    {
        sort(v.begin(), v.end());
        vector<int> dp(v.size() + 1, 0);
        for (int i = v.size() - 1; i >= 0; i--)
        {
            int j = bs(v, i + 1, v[i][1]);
            dp[i] = max(dp[j] + 1, dp[i + 1]);
        }
        return v.size() - dp[0];
    }
};

// Time Complexity - O(NlogN)
// Space Complexity - O(N)

class Solution
{
    int bs(vector<vector<int>> &v, int l, int t)
    {
        for (int r = v.size(); l < r;)
        {
            int md = l + (r - l) / 2;
            (v[md][0] < t) ? l = md + 1 : r = md;
        }
        return l;
    }

    int rec(vector<vector<int>> &v, vector<int> &dp, int i)
    {
        if (i == v.size())
            return 0;
        if (dp[i] != -1)
            return dp[i];
        int j = bs(v, i + 1, v[i][1]);
        return dp[i] = max(rec(v, dp, j) + 1, rec(v, dp, i + 1));
    }

public:
    int eraseOverlapIntervals(vector<vector<int>> &v)
    {
        sort(v.begin(), v.end());
        vector<int> dp(v.size(), -1);
        return v.size() - rec(v, dp, 0);
    }
};

// MLE

class Solution
{
    int rec(vector<vector<int>> &v, vector<vector<int>> &dp, int i, int j)
    {
        if (i == v.size())
            return 0;
        if (dp[i][j + 1] != -1)
            return dp[i][j + 1];
        if (j >= 0 && v[i][0] < v[j][1])
            return dp[i][j + 1] = min(rec(v, dp, i + 1, j), rec(v, dp, i + 1, i)) + 1;
        return dp[i][j + 1] = rec(v, dp, i + 1, i);
    }

public:
    int eraseOverlapIntervals(vector<vector<int>> &v)
    {
        sort(v.begin(), v.end());
        vector dp(v.size(), vector<int>(v.size() + 1, -1));
        return rec(v, dp, -1, 0);
    }
};

// @lc app=leetcode id=435 lang=cpp