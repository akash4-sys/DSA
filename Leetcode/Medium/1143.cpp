#include "../../headers.h"

// Time Complexity - O(nm)
// Space Complexity - O(nm)

class Solution
{
public:
    int longestCommonSubsequence(string s, string r)
    {
        vector<vector<int>> grid(s.length() + 1, vector<int>(r.length() + 1, 0));
        for (int i = 0; i < s.size(); i++)
            for (int j = 0; j < r.size(); j++)
                grid[i + 1][j + 1] = s[i] == r[j] ? grid[i][j] + 1 : max(grid[i + 1][j], grid[i][j + 1]);
        return grid[s.size()][r.size()];
    }
};

// Time Complexity - O(mn)
// Space Complexity - O(n)

class Solution
{
public:
    int longestCommonSubsequence(string s, string r)
    {
        vector<int> dp(r.size() + 1, 0);
        for (int i = 1; i <= s.size(); i++)
        {
            int prev = 0;
            for (int j = 1; j <= r.size(); j++)
            {
                int curr = dp[j];
                dp[j] = max({dp[j], dp[j - 1], prev + (s[i - 1] == r[j - 1])});
                prev = curr;
            }
        }
        return dp[r.size()];
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
            return dp[i][j] = lcs(dp, s, r, i + 1, j + 1) + 1;
        return dp[i][j] = max(lcs(dp, s, r, i + 1, j), lcs(dp, s, r, i, j + 1));
    }

public:
    int longestCommonSubsequence(string s, string r) 
    {
       vector dp(s.size(), vector<int>(r.size(), -1));
       return lcs(dp, s, r, 0, 0);
    }
};