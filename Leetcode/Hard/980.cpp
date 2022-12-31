#include "../../headers.h"

class Solution
{
    int dirs[4][2] = {{0, 1}, {0, -1}, {1, 0}, {-1, 0}};
    int dfs(vector<vector<int>> &grid, int steps, int i, int j)
    {
        if (i < 0 || j < 0 || i >= grid.size() || j >= grid[0].size() || grid[i][j] == -1)
            return 0;
        if (grid[i][j] == 2)
            return !steps;

        int ans = 0;
        grid[i][j] = -1;
        for (auto [x, y]: dirs)
            ans += dfs(grid, steps - 1, i + x, j + y);
        grid[i][j] = 0;
        return ans;
    }

public:
    int uniquePathsIII(vector<vector<int>> &grid)
    {
        int m = grid.size(), n = grid[0].size(), tSteps = 1, x, y;
        for (int i = 0; i < m; i++)
            for (int j = 0; j < n; j++)
            {
                if (grid[i][j] == 1)
                    x = i, y = j;
                tSteps += !grid[i][j];
            }
        return dfs(grid, tSteps, x, y);
    }
};