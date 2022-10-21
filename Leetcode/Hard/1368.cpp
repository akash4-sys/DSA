#include "../../headers.h"

// correct answer but for some reason wrong nitpicking
class Solution
{
    int d[4][2] = {{0, 1}, {0, -1}, {1, 0}, { -1, 0}}, cost = 0;
    queue<pair<int, int>> q;
    void dfs(vector<vector<int>>& grid, vector<vector<int>>& dp, int i, int j) 
    {
        if (i < 0 || i >= grid.size() || j < 0 || j >= grid[0].size() || dp[i][j] != -1)
            return;
        dp[i][j] = cost;
        q.push({i, j});
        dfs(grid, dp, i + d[grid[i][j] - 1][0], j + d[grid[i][j] - 1][1]);
    }

    public:
    int minCost(vector<vector<int>>& grid) 
    {
        vector<vector<int>> dp(grid.size(), vector<int>(grid[0].size(), -1));
        dfs(grid, dp, 0, 0);
        while (!q.empty()) 
        {
            cost++;
            for(int k = 0, sz = q.size(); k < sz; k++)
            {
                auto &[i, j] = q.front();
                q.pop();
                for(auto &[x, y]: d)
                    dfs(grid, dp, i + x, j + y);
            }
        }
        return dp[grid.size() - 1][grid[0].size() - 1];
    }
};