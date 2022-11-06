#include "../../headers.h"

// Solution 3: To Convert any recursive solution into tabulation solution
// Solution 2: First we'll make it 1 based indexing

// Time Complexity O(N^2)
// Space Complexity O(N^2)
class Solution
{
public:
    bool isMatch(string s, string p)
    {
        vector<vector<int>> dp(s.size() + 1, vector<int>(p.size() + 1, -1));
        dp[0][0] = 1;

        for (int i = 1; i <= s.size(); i++)
            dp[i][0] = 0;
        for (int j = 1; j <= p.size(); j++)
        {
            int v = 1;
            for (int k = 1; k <= j; k++)
                if (p[k - 1] != '*')
                {
                    v = 0;
                    break;
                }
            dp[0][j] = v;
        }

        for (int i = 1; i <= s.size(); i++)
            for (int j = 1; j <= p.size(); j++)
            {
                if (s[i - 1] == p[j - 1] || p[j - 1] == '?')
                    dp[i][j] = dp[i - 1][j - 1];
                else if (p[j - 1] == '*')
                    dp[i][j] = (dp[i - 1][j] || dp[i][j - 1]);
                else dp[i][j] =  0;
            }
        return dp[s.size()][p.size()];
    }
};



class Solution
{
    bool recurse(vector<vector<int>> &dp, string &s, string &p, int i, int j)
    {
        if (i == 0 && j == 0)
            return true;
        if (i > 0 && j == 0)
            return false;
        if (i == 0 && j > 0)
        {
            for (int k = 1; k <= j; k++)
                if (p[k - 1] != '*')
                    return false;
            return true;
        }

        if (dp[i][j] != -1)
            return dp[i][j];
        if (s[i - 1] == p[j - 1] || p[j - 1] == '?')
            return dp[i][j] = recurse(dp, s, p, i - 1, j - 1);
        if (p[j - 1] == '*')
            return dp[i][j] = recurse(dp, s, p, i - 1, j) || recurse(dp, s, p, i, j - 1);
        return false;
    }

public:
    bool isMatch(string s, string p)
    {
        vector<vector<int>> dp(s.size() + 1, vector<int>(p.size() + 1, -1));
        return recurse(dp, s, p, s.size(), p.size());
    }
};

class Solution
{
    bool recurse(vector<vector<int>> &dp, string &s, string &p, int i, int j)
    {
        if (i < 0 && j < 0)
            return true;
        if (i >= 0 && j < 0)
            return false;
        if (i < 0 && j >= 0)
        {
            for (int k = 0; k <= j; k++)
                if (p[k] != '*')
                    return false;
            return true;
        }

        if (dp[i][j] != -1)
            return dp[i][j];
        if (s[i] == p[j] || p[j] == '?')
            return dp[i][j] = recurse(dp, s, p, i - 1, j - 1);
        if (p[j] == '*')
            return dp[i][j] = recurse(dp, s, p, i - 1, j) || recurse(dp, s, p, i, j - 1);
        return false;
    }

public:
    bool isMatch(string s, string p)
    {
        vector<vector<int>> dp(s.size(), vector<int>(p.size(), -1));
        return recurse(dp, s, p, s.size() - 1, p.size() - 1);
    }
};

// Time Complexity O(N * M)
// Space Complexity O(N * M) + O(N + M)(auxiliary stack space)
class Solution
{
    bool recurse(string &s, string &p, int i, int j)
    {
        if (i < 0 && j < 0)
            return true;
        if (i >= 0 && j < 0)
            return false;
        if (i < 0 && j >= 0)
        {
            for (int k = 0; k <= j; k++)
                if (p[k] != '*')
                    return false;
            return true;
        }

        if (s[i] == p[j] || p[j] == '?')
            return recurse(s, p, i - 1, j - 1);
        if (p[j] == '*')
            return recurse(s, p, i - 1, j) || recurse(s, p, i, j - 1);
        return false;
    }

public:
    bool isMatch(string s, string p)
    {
        return recurse(s, p, s.size() - 1, p.size() - 1);
    }
};

// @lc app=leetcode id=44 lang=cpp