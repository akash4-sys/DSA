#include "../../headers.h"

class Solution
{
public:
    int numDistinct(string s, string p)
    {
        vector<int> dp(p.size(), 0);
        for (auto &c : s)
            for (int i = p.size() - 1; i >= 0; i--)
                if (p[i] == c)
                    dp[i] += (i > 0 ? dp[i - 1] : 1);
        return dp.back();
    }
};


class Solution
{
public:
    int numDistinct(string s, string p)
    {
        vector<int> dp(p.size() + 1, 0);
        dp[0] = 1;
        for (int i = 1; i <= s.size(); i++)
        {
            int prev = 0;
            for (int j = 1; j <= p.size(); j++)
            {
                int curr = dp[j];
                dp[j] += (s[i - 1] == p[j - 1] ? prev : 0);
                prev = curr;
            }
        }
        return dp[p.size()];
    }
};


class Solution
{
public:
    int numDistinct(string s, string p)
    {
        int n = s.size(), m = p.size(), mod = 1e9 + 7;
        vector dp(n + 1, vector<int>(m + 1, 0));
        for (int i = 0; i <= n; i++)
            dp[i][m] = 1;

        for (int i = n - 1; i >= 0; i--)
            for (int j = m - 1; j >= 0; j--)
                (dp[i][j] = (s[i] == p[j] ? dp[i + 1][j + 1] : 0) + dp[i + 1][j]) %= mod;
        return dp[0][0];
    }
};


//  Time Complexity - O(N^2)
// Space Complexity - O(N^2)

class Solution
{
    int dp[1001][1001];
    int rec(string &s, string &p, int i, int j)
    {
        if (j == p.size())
            return 1;
        if (i == s.size())
            return j == p.size();
        if (dp[i][j] != -1)
            return dp[i][j];
        
        int res = s[i] == p[j] ? rec(s, p, i + 1, j + 1) : 0;
        return dp[i][j] = res + rec(s, p, i + 1, j);
    }

public:
    int numDistinct(string s, string p)
    {
        memset(dp, -1, sizeof(dp));
        return rec(s, p, 0, 0);
    }
};