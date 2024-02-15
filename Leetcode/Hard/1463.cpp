#include "../../headers.h"

class Solution
{
    int dirs[3] = {-1, 0, 1}, n, m, dp[70][70][70];

    int dfs(vector<vector<int>> &grid, int ax, int ay, int by)
    {
        if (dp[ax][ay][by] != -1)
            return dp[ax][ay][by];

        int res = 0;
        for (int d1 : dirs)
            if (int x1 = ax + 1, y1 = ay + d1; x1 >= 0 && x1 < n && y1 >= 0 && y1 < m)
                for (int d2 : dirs)
                    if (int y2 = by + d2; y2 >= 0 && y2 < m)
                        res = max(res, dfs(grid, x1, y1, y2) + grid[x1][y1] + (y1 == y2 ? 0 : grid[x1][y2]));
        return dp[ax][ay][by] = res;
    }

public:
    int cherryPickup(vector<vector<int>> &grid)
    {
        n = grid.size(), m = grid[0].size();
        memset(dp, -1, sizeof(dp));
        return dfs(grid, 0, 0, m - 1) + grid[0][0] + grid[0][m - 1];
    }
};