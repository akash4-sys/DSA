#include "../../headers.h"

class Solution
{
public:
    vector<vector<int>> constructProductMatrix(vector<vector<int>> &grid)
    {
        long n = grid.size(), m = grid[0].size(), pf = 1, sf = 1, mod = 12345;
        vector ans(n, vector<int>(m, 1));
        for (int i = 0; i < n; i++)
            for (int j = 0; j < m; j++)
            {
                ans[i][j] = (pf * ans[i][j]) % mod;
                ans[n - i - 1][m - j - 1] = (sf * ans[n - i - 1][m - j - 1]) % mod;
                pf = (pf * grid[i][j]) % mod;
                sf = (sf * grid[n - i - 1][m - j - 1]) % mod;
            }
        return ans;
    }
};