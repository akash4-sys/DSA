#include "../../headers.h"

// Tabulation
// Time Complexity - O(N^2)
// Space Complexity - O(N^2)

class Solution 
{
    int dirs[2][2] = {{0, -1}, {-1, 0}};
public:
    int uniquePathsWithObstacles(vector<vector<int>>& grid) 
    {
        int m = grid.size(), n = grid[0].size();
        vector<vector<int>> dp(m, vector<int>(n, 0));
        dp[0][0] = 1;

        for (int i = 0; i < m; i++)
            for (int j = 0; j < n; j++)
            {
                for (auto [x, y] : dirs)
                    if (i + x >= 0 && j + y >= 0 && i + x < m && j + y < n && !grid[i + x][j + y])
                        dp[i][j] += dp[i + x][j + y];
                if (grid[i][j])
                    dp[i][j] = 0;
            }
        return dp[m - 1][n - 1];
    }
};




// Accepted
class Solution 
{
    int dirs[2][2] = {{0, 1}, {1, 0}}, n, m;
    int dfs(vector<vector<int>>& grid, vector<vector<int>> &dp, int i, int j)
    {
        if (i < 0 || j < 0 || i >= m || j >= n || grid[i][j])
            return 0;
        if (i == m - 1 && j == n - 1)
            return 1;
        if (dp[i][j] != -1)
            return dp[i][j];

        int ans = 0;
        grid[i][j] = 1;
        for (auto [x, y] : dirs)
            ans += dfs(grid, dp, i + x, j + y);
        grid[i][j] = 0;
        return dp[i][j] = ans;
    }

public:
    int uniquePathsWithObstacles(vector<vector<int>>& grid) 
    {
        m = grid.size(), n = grid[0].size();
        vector<vector<int>> dp(m, vector<int>(n, -1));
        return dfs(grid, dp, 0, 0);
    }
};




// TLE
class Solution 
{
    int dirs[2][2] = {{0, 1}, {1, 0}};
public:
    int uniquePathsWithObstacles(vector<vector<int>>& grid, int i = 0, int j = 0) 
    {
        if (i < 0 || j < 0 || i >= grid.size() || j >= grid[0].size() || grid[i][j])
            return 0;
        if (i == grid.size() - 1 && j == grid[0].size() - 1)
            return 1;

        int ans = 0;
        grid[i][j] = 1;
        for (auto [x, y] : dirs)
            ans += uniquePathsWithObstacles(grid, i + x, j + y);
        grid[i][j] = 0;
        return ans;
    }
};