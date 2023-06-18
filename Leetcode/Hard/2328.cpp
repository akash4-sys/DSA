#include "../../headers.h"

class Solution
{
    using v = vector<vector<int>>;
    int m, n, dirs[4][2] = {{1, 0}, {0, 1}, {-1, 0}, {0, -1}}, mod = 1e9 + 7;

    int dfs(v &grid, v &dp, int i, int j, int prev)
    {
        if (i < 0 || j < 0 || i >= m || j >= n || prev >= grid[i][j])
            return 0;
        if (dp[i][j] != -1)
            return dp[i][j];
        
        int res = 1;
        for (auto [dx, dy] : dirs)
            (res += dfs(grid, dp, i + dx, j + dy, grid[i][j])) %= mod;
        return dp[i][j] = res;
    }

public:
    int countPaths(v &grid)
    {
        int ans = 0;
        m = grid.size(), n = grid[0].size();
        vector dp(m, vector<int>(n, -1));

        for (int i = 0; i < m; i++)
            for (int j = 0; j < n; j++)
                (ans += dfs(grid, dp, i, j, 0)) %= mod;
        return ans;
    }
};