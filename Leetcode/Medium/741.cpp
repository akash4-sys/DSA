#include "../../headers.h"

class Solution
{
    int n, dp[50][50][50][50];
    int dfs(vector<vector<int>> &grid, int ax, int ay, int bx, int by)
    {
        if (ax == n - 1 && ay == n - 1 && !bx && !by)
            return 0;
        if (dp[ax][ay][bx][by] != -1)
            return dp[ax][ay][bx][by];
        
        int res = -10000;
        for (int d1 : {0, 1})
            if (int x1 = ax + d1, y1 = ay + !d1; x1 >= 0 && x1 < n && y1 >= 0 && y1 < n && grid[x1][y1] != -1)
            {
                int k1 = grid[x1][y1];
                grid[x1][y1] = 0;
                for (int d2 : {0, 1})
                    if (int x2 = bx - d2, y2 = by - !d2; x2 >= 0 && x2 < n && y2 >= 0 && y2 < n && grid[x2][y2] != -1)
                    {
                        int k2 = grid[x2][y2];
                        grid[x2][y2] = 0;
                        res = max(res, dfs(grid, x1, y1, x2, y2) + k1 + k2);
                        grid[x2][y2] = k2;
                    }
                grid[x1][y1] = k1;
            }
        return dp[ax][ay][bx][by] = res;
    }

public:
    int cherryPickup(vector<vector<int>> &grid)
    {
        n = grid.size();
        if (n == 1)
            return grid[0][0];

        memset(dp, -1, sizeof(dp));
        return max(dfs(grid, 0, 0, n - 1, n - 1), 0);
    }
};