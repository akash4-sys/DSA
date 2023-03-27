#include "../../headers.h"

class Solution
{
public:
    int minPathSum(vector<vector<int>> &grid)
    {
        int m = grid.size(), n = grid[0].size();
        vector<int> dp(m, grid[0][0]);
        for (int i = 1; i < m; i++)
            dp[i] = dp[i - 1] + grid[i][0];
        for (int j = 1; j < n; j++)
        {
            dp[0] += grid[0][j];
            for (int i = 1; i < m; i++)
                dp[i] = min(dp[i - 1], dp[i]) + grid[i][j];
        }
        return dp[m - 1];
    }
};


class Solution
{
public:
    int minPathSum(vector<vector<int>> &grid)
    {
        int m = grid.size(), n = grid[0].size();
        vector<vector<int>> dp(m, vector<int>(n, grid[0][0]));
        for (int j = 1; j < n; j++)
            dp[0][j] = dp[0][j - 1] + grid[0][j];
        for (int i = 1; i < m; i++)
        {
            dp[i][0] = dp[i - 1][0] + grid[i][0];
            for (int j = 1; j < n; j++)
                dp[i][j] = min(dp[i - 1][j], dp[i][j - 1]) + grid[i][j];
        }
        return dp[m - 1][n - 1];
    }
};


class Solution
{
    int m, n;
    int dfs(vector<vector<int>> &grid, vector<vector<int>> &dp, int i, int j)
    {
        if (i < 0 || j < 0 || i >= m || j >= n)
            return INT_MAX;
        if (i == m - 1 && j == n - 1)
            return grid[i][j];
        if (dp[i][j] != -1)
            return dp[i][j];
        return dp[i][j] = grid[i][j] + min(dfs(grid, dp, i + 1, j), dfs(grid, dp, i, j + 1));
    }

public:
    int minPathSum(vector<vector<int>> &grid)
    {
        m = grid.size(), n = grid[0].size();
        vector<vector<int>> dp(m, vector<int>(n, -1));
        return dfs(grid, dp, 0, 0);
    }
};