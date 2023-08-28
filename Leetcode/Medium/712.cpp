#include "../../headers.h"

class Solution
{
    int lcs(string s, string r)
    {
        vector<int> dp(r.size() + 1, 0);
        for (int i = 1; i <= s.size(); i++)
        {
            int prev = 0;
            for (int j = 1; j <= r.size(); j++)
            {
                int curr = dp[j];
                dp[j] = max({dp[j], dp[j - 1], prev + (s[i - 1] == r[j - 1] ? s[i - 1] : 0)});
                prev = curr;
            }
        }
        return dp[r.size()];
    }

public:
    int minimumDeleteSum(string &s, string &r)
    {
        int a = accumulate(s.begin(), s.end(), 0), b = accumulate(r.begin(), r.end(), 0);
        return a + b - (lcs(s, r) * 2);
    }
};


class Solution
{
    int lcs(vector<vector<int>> &dp, string &s, string &r, int i, int j)
    {
        if (i == s.size() || j == r.size())
            return 0;
        if (dp[i][j] != -1)
            return dp[i][j];
        if (s[i] == r[j])
            return dp[i][j] = lcs(dp, s, r, i + 1, j + 1) + s[i];
        return dp[i][j] = max(lcs(dp, s, r, i + 1, j), lcs(dp, s, r, i, j + 1));
    }

public:
    int minimumDeleteSum(string &s, string &r)
    {
        int a = accumulate(s.begin(), s.end(), 0), b = accumulate(r.begin(), r.end(), 0);
        vector dp(s.size(), vector<int>(r.size(), -1));
        return a + b - (lcs(dp, s, r, 0, 0) * 2);
    }
};

// @lc app=leetcode id=712 lang=cpp