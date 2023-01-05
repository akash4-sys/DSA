#include "../../headers.h"

class Solution 
{
public:
    int maxTwoEvents(vector<vector<int>>& v)
    {
        sort(v.begin(), v.end(), greater<vector<int>>());
        map<int, int> mp;
        int ans = 0, maxi = 0;
        for (auto &e : v)
        {
            auto it = mp.upper_bound(e[1]);
            maxi = max(maxi, e[2]);
            mp[e[0]] = maxi;
            if (it == mp.end())
                ans = max(ans, maxi);
            else
                ans = max(ans, e[2] + it->second);
        }
        return ans;
    }
};


class Solution
{
    int recurse(vector<vector<int>> &v, vector<vector<int>> &dp, int i, int k)
    {
        if (i == v.size() || k == 2)
            return 0;
        if (dp[i][k] != -1)
            return dp[i][k];
        vector<int> q = {v[i][1], INT_MAX, INT_MAX};
        int it = upper_bound(v.begin(), v.end(), q) - v.begin();
        return dp[i][k] = max(recurse(v, dp, it, k + 1) + v[i][2], recurse(v, dp, i + 1, k));
    }

public:
    int maxTwoEvents(vector<vector<int>> &v)
    {
        sort(v.begin(), v.end());
        vector<vector<int>> dp(v.size(), vector<int>(2, -1));
        return recurse(v, dp, 0, 0);
    }
};


// TLE But correct
// Not able to memoize
class Solution
{
    int recurse(vector<vector<int>> &v, int i, int k, int e)
    {
        if (i == v.size() || !k)
            return 0;
        if (v[i][0] <= e)
            return recurse(v, i + 1, k, e);
        return max(recurse(v, i + 1, k - 1, v[i][1]) + v[i][2], recurse(v, i + 1, k, e));
    }

public:
    int maxTwoEvents(vector<vector<int>> &v)
    {
        sort(v.begin(), v.end(), [&](const auto &a, const auto &b)
             { return a[1] < b[1]; });
        return max(recurse(v, 1, 1, v[0][1]) + v[0][2], recurse(v, 1, 2, -1));
    }
};

// @lc app=leetcode id=2054 lang=cpp