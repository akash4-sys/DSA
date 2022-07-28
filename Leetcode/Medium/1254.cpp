#include "../../headers.h"

class Solution
{
public:
    vector<vector<int>> dir = {{0, 1}, {1, 0}, {-1, 0}, {0, -1}};
    bool checkForMore(vector<vector<int>> &grid, int i, int j)
    {
        if (i == 0 || j == 0 || i == grid.size() - 1 || j == grid[0].size() - 1)
            return false;

        bool ans = true;
        for (auto d : dir)
        {
            int nr = i + d[0];
            int nc = j + d[1];
            if (nr >= 0 && nc >= 0 && nr < grid.size() && nc < grid[0].size() && grid[nr][nc] == 0)
            {
                grid[nr][nc] = 1;
                ans = (ans & checkForMore(grid, nr, nc));
            }
        }
        return ans;
    }
    int closedIsland(vector<vector<int>> &grid)
    {
        int ans = 0;
        for (int i = 1; i < grid.size() - 1; i++)
        {
            for (int j = 1; j < grid[0].size() - 1; j++)
            {
                if (grid[i][j])
                    continue;
                grid[i][j] = 1;
                if (checkForMore(grid, i, j))
                    ans++;
            }
        }
        return ans;
    }
};