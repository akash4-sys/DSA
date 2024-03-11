#include "../../headers.h"

class PrefixSum
{
    vector<vector<int>> pf;
public:
    PrefixSum(vector<vector<int>> &grid)
    {
        pf = vector(grid.size() + 1, vector<int>(grid[0].size() + 1, 0));
        for (int i = 0; i < grid.size(); i++)
            for (int j = 0; j < grid[0].size(); j++)
                pf[i + 1][j + 1] = (pf[i + 1][j] + pf[i][j + 1] + grid[i][j]) - pf[i][j];
    }

    int sumRegion(int x1, int y1, int x2, int y2)
    {
        int above = pf[x2 + 1][y1], left = pf[x1][y2 + 1], topLeft = pf[x1][y1];
        return pf[x2 + 1][y2 + 1] + topLeft - left - above;
    }
};

class Solution
{
public:
    int countSubmatrices(vector<vector<int>> &grid, int k)
    {
        PrefixSum pf(grid);
        int ans = 0;
        for (int i = 0; i < grid.size(); ++i)
            for (int j = 0; j < grid[0].size(); ++j)
                ans += (pf.sumRegion(0, 0, i, j) <= k);
        return ans;
    }
};