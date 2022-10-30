#include "../../headers.h"

class Solution
{
public:
    int matrixScore(vector<vector<int>> &grid)
    {
        int m = grid.size(), n = grid[0].size(), ans = (1 << (n - 1)) * m;
        for(int j = 1; j < n; ++j)
        {
            int curr = 0;
            for(int i = 0; i < m; i++)
                curr += grid[i][j] == grid[i][0];
            ans += max(curr, m - curr) * (1 << n - j - 1);
        }
        return ans;
    }
};