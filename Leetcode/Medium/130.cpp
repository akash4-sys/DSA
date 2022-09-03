#include "../../headers.h"

class Solution
{
    int dirs[4][2] = {{0, 1}, {0, -1}, {1, 0}, {-1, 0}};
    void dfs(vector<vector<char>> &grid, int i, int j)
    {
        if (i < 0 || j < 0 || i >= grid.size() || j >= grid[0].size() || grid[i][j] == 'X' || grid[i][j] == '1')
            return;
        grid[i][j] = '1';
        for (auto &[x, y] : dirs)
            dfs(grid, x + i, y + j);
        return;
    }

public:
    void solve(vector<vector<char>> &grid)
    {
        int m = grid.size(), n = grid[0].size();
        for (int i = 0; i < m; i++)
        {
            if (grid[i][0] == 'O')
                dfs(grid, i, 0);
            if(grid[i][n - 1] == 'O')
                dfs(grid, i, n - 1);
        }
        for (int j = 0; j < n; j++)
        {
            if (grid[0][j] == 'O')
                dfs(grid, 0, j);
            if(grid[m - 1][j] == 'O')
                dfs(grid, m - 1, j);
        }

        for(int i = 0; i < m; i++)
            for(int j = 0; j < n; j++)
                grid[i][j] = (grid[i][j] == '1') ? 'O' : 'X';
    }
};