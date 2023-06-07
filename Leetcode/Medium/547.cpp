#include "../../headers.h"

class Solution
{
    void dfs(vector<vector<int>> &grid, int u)
    {
        for(int v = 0; v < grid.size(); v++)
            if(grid[u][v]) {
                grid[u][v] = grid[v][u] = 0;
                dfs(grid, v);
            }
    }

public:
    int findCircleNum(vector<vector<int>> &grid)
    {
        int ans = 0;
        for (int u = 0; u < grid.size(); u++)
            if(grid[u][u])
                dfs(grid, u), ans++;
        return ans;
    }
};