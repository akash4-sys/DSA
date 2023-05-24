#include "headers.h"

class Solution
{
    int dirs[3][2] = {{-1, 1}, {0, 1}, {1, 1}}, n, m;
    int dfs(vector<vector<int>> &g, vector<vector<int>> &dp, int i, int j)
    {
        if (dp[i][j] != -1)
            return dp[i][j];

        int res = 0;
        for (auto d : dirs)
        {
            int x = i + d[0], y = j + d[1];
            if (x >= 0 && x < n && y >= 0 && y < m && g[x][y] > g[i][j])
                res = max(res, dfs(g, dp, i + d[0], j + d[1]) + 1);
        }
        return dp[i][j] = res;
    }

public:
    int maxMoves(vector<vector<int>> &g)
    {
        n = g.size(), m = g[0].size();
        vector<vector<int>> dp(n, vector<int>(m, -1));

        int ans = 0;
        for (int i = 0; i < g.size(); i++)
            ans = max(ans, dfs(g, dp, i, 0));
        return ans;
    }
};