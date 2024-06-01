#include "../../headers.h"

class Solution
{
public:
    long long numberOfRightTriangles(vector<vector<int>> &grid)
    {
        int n = grid.size(), m = grid[0].size();
        vector col(n, vector<int>(m, 0)), row = col;
        for (int j = 0; j < m; j++)
            for (int i = 0, sum = 0; i < n; i++)
                sum += grid[i][j], col[i][j] = sum;

        for (int i = 0; i < n; i++)
            for (int j = 0, sum = 0; j < m; j++)
                sum += grid[i][j], row[i][j] = sum;
        
        long long ans = 0;
        for (int i = 0; i < n; i++)
            for (int j = 0; j < m; j++)
                if (grid[i][j])
                    ans += ((row[i][m - 1] - 1) * (col[n - 1][j] - 1) * 1LL);
        return ans;
    }
};