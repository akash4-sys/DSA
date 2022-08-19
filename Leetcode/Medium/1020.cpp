#include "../../headers.h"

class Solution
{
    vector<vector<int>> dirs = {{0, 1}, {1, 0}, {-1, 0}, {0, -1}};

    void dfs(vector<vector<int>> &grid, int i, int j)
    {
        if(i < 0 || j < 0 || i >= grid.size()|| j >= grid[0].size() || !grid[i][j])
            return;
        grid[i][j] = 0;
        for(auto d: dirs)
            dfs(grid, i + d[0], j + d[1]);
    }

public:
    int numEnclaves(vector<vector<int>> &grid)
    {
        int c = grid.size(), r = grid[0].size();
        
        for (int i = 0; i < r; i++)
            dfs(grid, 0, i), dfs(grid, c-1, i);
        for (int i = 0; i < c; i++)
            dfs(grid, i, 0), dfs(grid, i, r-1);
        
        int ans = 0;
        for(auto r: grid)
            for(auto cell: r)
                ans += cell;

        return ans;
    }
};