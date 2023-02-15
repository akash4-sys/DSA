#include "../../headers.h"

#define vv vector<vector<int>>
class Solution
{
    int n, m;
    vv pac, atl, ans;
    void dfs(vv &grid, int i, int j, vv &ocean)
    {
        if (ocean[i][j])
            return;
        ocean[i][j] = 1;
        if (atl[i][j] == pac[i][j])
            ans.push_back({i, j});
        for (int dirs[4][2] = {{0, 1}, {0, -1}, {1, 0}, {-1, 0}}; auto [dx, dy]: dirs)
        {
            int x = i + dx, y = j + dy;
            if (x >= 0 && y >= 0 && x < n && y < m && grid[i][j] <= grid[x][y])
                dfs(grid, x, y, ocean);
        }
    }

public:
    vv pacificAtlantic(vv &grid)
    {
        n = grid.size(), m = grid[0].size();
        pac = atl = vv(n, vector<int>(m));

        for (int i = 0; i < m; i++)
        {
            dfs(grid, 0, i, pac); 
            dfs(grid, n - 1, i, atl);
        }
        for (int i = 0; i < n; i++)
        {
            dfs(grid, i, 0, pac);
            dfs(grid, i, m - 1, atl);
        }
        return ans;
    }
};