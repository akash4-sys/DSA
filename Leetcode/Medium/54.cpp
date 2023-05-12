#include "../../headers.h"

class Solution
{
    int dir[4][2] = {{0, 1}, {1, 0}, {0, -1}, {-1, 0}};
public:
    vector<int> spiralOrder(vector<vector<int>> &grid)
    {
        int i = 0, j = -1, d = 0, n = grid.size(), m = grid[0].size();
        vector<int> ans, steps = {m, n - 1};
        while (steps[d % 2])
        {
            for (int k = 0; k < steps[d % 2]; k++)
            {
                i += dir[d][0];
                j += dir[d][1];
                ans.push_back(grid[i][j]);
            }
            steps[d % 2]--;
            d = (d + 1) % 4;
        }
        return ans;
    }
};




class Solution
{
public:
    vector<int> spiralOrder(vector<vector<int>> &grid)
    {
        if (grid.empty() || grid[0].empty())
            return {};
            
        vector<int> ans;
        int m = grid.size(), n = grid[0].size();

        for (int i = 0; ans.size() < m * n; ++i)
        {
            for (int j = i; j < n - i; ++j)
                ans.push_back(grid[i][j]);

            for (int j = i + 1; j < m - i; ++j)
                ans.push_back(grid[j][n - i - 1]);

            for (int j = n - i - 2; m - i - 1 != i && j >= i; --j)
                ans.push_back(grid[m - i - 1][j]);
                
            for (int j = m - i - 2; n - i - 1 != i && j > i; --j)
                ans.push_back(grid[j][i]);
        }
        return ans;
    }
};