#include "../../headers.h"

class Solution
{
    void dfs(vector<vector<int>> &grid, int i)
    {
        for(int j = 0; j < grid.size(); j++)
            if(grid[i][j])
            {
                grid[i][j] = 0;
                grid[j][i] = 0;
                dfs(grid, j);
            }
    }

public:
    int findCircleNum(vector<vector<int>> &grid)
    {
        int ans = 0;
        for (int i = 0; i < grid.size(); i++)
            if(grid[i][i])
                dfs(grid, i), ans++;
        return ans;
    }
};