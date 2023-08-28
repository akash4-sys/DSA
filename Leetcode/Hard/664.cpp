#include "../../headers.h"

class Solution
{
    int dp[101][101];
    int rec(string &s, int l, int r)
    {
        if (dp[l][r] != -1)
            return dp[l][r];

        int j = -1, res = INT_MAX;
        for (int i = l; i < r; i++)
        {
            if (s[i] != s[r] && j == -1)
                j = i;
            if (j != -1)
                res = min(res, rec(s, j, i) + rec(s, i + 1, r) + 1);
        }
        return dp[l][r] = j == -1 ? 0 : res;
    }

public:
    int strangePrinter(string s)
    {
        string r;
        r += s[0];
        for (char c : s)
            if (c != r.back())
                r += c;

        memset(dp, -1, sizeof(dp));
        return rec(r, 0, r.size() - 1) + 1;
    }
};


// @lc app=leetcode id=664 lang=cpp