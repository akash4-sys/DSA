#include "../../headers.h"

// Time Complexity - O(m*n)
// Space Complexity - O(n)

class Solution
{
public:
    int minDistance(string s, string t)
    {
        int it, m = s.length(), n = t.length();
        vector<int> dp(n + 1, 0);

        for (int i = 0; i <= n; i++)
            dp[i] = i;

        for (int i = 1; i <= m; i++)
        {
            int prev = i - 1;
            dp[0] = i;
            for (int j = 1; j <= n; j++)
            {
                int curr = dp[j];
                dp[j] = (s[i - 1] == t[j - 1]) ? prev : 1 + min({dp[j], dp[j - 1], prev});
                prev = curr;
            }
        }
        return dp[n];
    }
};

// Time Complexity - O(m*n)
// Space Complexity - O(m*n)

class Solution
{
public:
    int minDistance(string s, string t)
    {
        int it, m = s.length(), n = t.length();
        vector<vector<int>> dp(m + 1, vector<int>(n + 1, 0));

        for (int i = 0; i <= m; i++)
            dp[i][0] = i;
        for (int i = 0; i <= n; i++)
            dp[0][i] = i;

        for (int i = 1; i <= m; i++)
            for (int j = 1; j <= n; j++)
                dp[i][j] = (s[i - 1] == t[j - 1]) ? dp[i - 1][j - 1] : 1 + min({dp[i - 1][j], dp[i][j - 1], dp[i - 1][j - 1]});
        return dp[m][n];
    }
};

// Time Complexity - O(m*n)
// Space Complexity - O(m*n) + Recursion stack space

class Solution
{
    vector<vector<int>> dp;
    int editDistance(string s, string t, int i, int j)
    {
        if (i < 0)
            return j + 1;
        if (j < 0)
            return i + 1;

        if (dp[i][j] != -1)
            return dp[i][j];
        if (s[i] == t[j])
            return dp[i][j] = editDistance(s, t, i - 1, j - 1);
        else
        {
            int insert = editDistance(s, t, i, j - 1);
            int del = editDistance(s, t, i - 1, j);
            int replace = editDistance(s, t, i - 1, j - 1);
            return dp[i][j] = 1 + min({insert, del, replace});
        }
    }

public:
    int minDistance(string s, string t)
    {
        dp = vector<vector<int>>(s.length(), vector<int>(t.length(), -1));
        return editDistance(s, t, s.length() - 1, t.length() - 1);
    }
};

// Recursive Solution
// Time Complexity - O(min(m^3, n^3))
// Space Complexity - O(n)

class Solution
{
    int editDistance(string s, string t, int sl, int tl)
    {
        if (!sl)
            return tl;
        if (!tl)
            return sl;

        if (s[sl - 1] == t[tl - 1])
            return editDistance(s, t, sl - 1, tl - 1);
        else
        {
            int insert = editDistance(s, t, sl, tl - 1);
            int del = editDistance(s, t, sl - 1, tl);
            int replace = editDistance(s, t, sl - 1, tl - 1);
            return 1 + min({insert, del, replace});
        }
    }

public:
    int minDistance(string s, string t)
    {
        return editDistance(s, t, s.length(), t.length());
    }
};