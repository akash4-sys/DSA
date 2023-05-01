#include "headers.h"

class Solution
{
    int dirs[4][2] = {{1, 0}, {0, 1}, {-1, 0}, {0, -1}};
    int dfs(vector<vector<int>> &grid, int i, int j)
    {
        if (i < 0 || j < 0 || i == grid.size() || j == grid[0].size() || !grid[i][j])
            return 0;
        int sum = grid[i][j];
        grid[i][j] = 0;
        for (auto [x, y] : dirs)
            sum += dfs(grid, i + x, j + y);
        return sum;
    }

public:
    int findMaxFish(vector<vector<int>> &grid)
    {
        int ans = 0;
        for (int i = 0; i < grid.size(); i++)
            for (int j = 0; j < grid[0].size(); j++)
                if (grid[i][j])
                    ans = max(ans, dfs(grid, i, j));
        return ans;
    }
};