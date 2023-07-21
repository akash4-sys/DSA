#include "../../headers.h"

class Solution
{
public:
    int maximalSquare(vector<vector<char>> &mat)
    {
        int m = mat.size(), n = mat[0].size(), ans = 0;
        vector dp(m + 1, vector<int>(n + 1, 0));
        for (int i = m - 1; i >= 0; i--)
            for (int j = n - 1; j >= 0; j--)
            {
                dp[i][j] = mat[i][j] == '1' ? min({dp[i][j + 1], dp[i + 1][j], dp[i + 1][j + 1]}) + 1 : 0;
                ans = max(ans, dp[i][j]);
            }
        return ans * ans;
    }
};


class Solution
{
public:
    int maximalSquare(vector<vector<char>> &mat)
    {
        int m = mat.size(), n = mat[0].size(), ans = 0;
        vector dp(m, vector<int>(n, 0));

        for (int i = 0; i < m; i++)
            ans = max(ans, dp[i][n - 1] = mat[i][n - 1] - '0');
        for (int j = 0; j < n; j++)
            ans = max(ans, dp[m - 1][j] = mat[m - 1][j] - '0');

        for (int i = m - 2; i >= 0; i--)
            for (int j = n - 2; j >= 0; j--)
            {
                if (mat[i][j] == '1')
                {
                    int len = min(dp[i + 1][j], dp[i][j + 1]);
                    dp[i][j] = dp[i + len][j + len] ? len + 1 : max(len, 1);
                }
                ans = max(ans, dp[i][j]);
            }
        return ans * ans;
    }
};

// @lc app=leetcode id=221 lang=cpp