#include "../../headers.h"

class Solution
{
public:
    int dfs(vector<vector<int>> &grid, int i, int j)
    {
        if (i >= grid.size())
            return j;

        if ((j <= 0 && !grid[i][j]) || (j == grid[0].size() - 1 && grid[i][j]))
            return -1;

        if (grid[i][j])
            return (grid[i][j + 1]) ? dfs(grid, i + 1, j + 1) : -1;
        else
            return (!grid[i][j-1]) ?dfs(grid, i + 1, j - 1) : -1;
        return 10;
    }

    vector<int> findBall(vector<vector<int>> &grid)
    {
        vector<int> ans;
        int enter = 0;
        while (enter < grid[0].size())
        {
            ans.push_back(dfs(grid, 0, enter));
            enter++;
        }
        return ans;
    }
};