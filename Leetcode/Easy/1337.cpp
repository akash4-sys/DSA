#include "../../headers.h"

class Solution
{
public:
    vector<int> kWeakestRows(vector<vector<int>> &grid, int k)
    {
        vector<int> ans(k);
        for (int i = 0; i < grid.size(); i++)
            grid[i].push_back(i);

        sort(grid.begin(), grid.end());
        for (int i = 0, n = grid[0].size(); i < k; i++)
            ans[i] = grid[i][n - 1];
        return ans;
    }
};