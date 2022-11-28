#include "headers.h"

class Solution
{
public:
    vector<vector<int>> onesMinusZeros(vector<vector<int>> &grid)
    {
        int n = grid.size(), m = grid[0].size();
        vector<int> r(n, 0), c(m, 0);
        for (int i = 0; i < n; i++)
            for (int j = 0; j < m; j++)
                r[i] += grid[i][j], c[j] += grid[i][j];

        for (int i = 0; i < n; i++)
            for (int j = 0; j < m; j++)
                grid[i][j] = r[i] + c[j] - (n - r[i]) - (m - c[j]);
        return grid;
    }
};