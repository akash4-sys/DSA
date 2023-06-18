#include "../../headers.h"

class Solution
{
public:
    int minimumTotal(vector<vector<int>> &mat)
    {
        vector<int> dp(201, 0);
        for (int i = mat.size() - 1; i >= 0; i--)
            for (int j = mat[i].size() - 1, nxt = dp[j + 1]; j >= 0; j--)
            {
                int prev = dp[j];
                dp[j] = min(dp[j], nxt) + mat[i][j];
                nxt = prev;
            }
        return dp[0];
    }
};

// Time Complexity - O(N^2)
// Space Complexity - O(N^2)

class Solution
{
public:
    int minimumTotal(vector<vector<int>> &mat)
    {
        vector dp(201, vector<int>(200, 0));
        for (int i = mat.size() - 1; i >= 0; i--)
            for (int j = mat[i].size() - 1; j >= 0; j--)
                dp[i][j] = min(dp[i + 1][j], dp[i + 1][j + 1]) + mat[i][j];
        return dp[0][0];
    }
};

// Time Complexity - O(N^2)
// Space Complexity - O(N^2)

class Solution
{
    int dp[200][200];
    int dfs(vector<vector<int>> &mat, int i, int j)
    {
        if (i == mat.size())
            return 0;
        if (dp[i][j] != -1)
            return dp[i][j];
        return dp[i][j] = min(dfs(mat, i + 1, j), dfs(mat, i + 1, j + 1)) + mat[i][j];
    }

public:
    int minimumTotal(vector<vector<int>> &mat)
    {
        memset(dp, -1, sizeof(dp));
        return dfs(mat, 0, 0);
    }
};