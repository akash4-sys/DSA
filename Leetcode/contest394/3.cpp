#include "../../headers.h"

class Solution
{
    int dp[1001][11];
    int rec(vector<vector<int>> &v, int i, int val)
    {
        if (i == v.size())
            return 0;
        if (dp[i][val] != -1)
            return dp[i][val];
        
        int res = 0;
        for (int j = 0; j < 10; j++)
            if (j != val - 1)
                res = max(res, rec(v, i + 1, j + 1) + v[i][j]);
        return dp[i][val] = res;
    }

public:
    int minimumOperations(vector<vector<int>> &grid)
    {
        int n = grid.size(), m = grid[0].size();
        vector v(m, vector<int>(10, 0));
        for (int j = 0; j < m; j++)
            for (int i = 0; i < n; i++)
                v[j][grid[i][j]]++;

        memset(dp, -1, sizeof(dp));
        return m * n - rec(v, 0, 0);
    }
};