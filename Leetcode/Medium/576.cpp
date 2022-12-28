#include "../../headers.h"

#define vv vector<vector<int>>
#define vvv vector<vector<vector<int>>>

class Solution
{
    int dirs[4][2] = {{0, 1}, {0, -1}, {1, 0}, {-1, 0}}, mod = 1e9 + 7;

public:
    int findPaths(int m, int n, int stp, int x, int y)
    {
        vvv dp(m, vv(n, vector<int>(stp + 1, 0)));

        for (int k = 1; k <= stp; k++)
            for (int i = 0; i < m; i++)
                for (int j = 0; j < n; j++)
                    for (auto [dx, dy] : dirs)
                        if (i + dx < 0 || j + dy < 0 || i + dx >= m || j + dy >= n)
                            dp[i][j][k]++;
                        else
                            dp[i][j][k] = (dp[i][j][k] + dp[i + dx][j + dy][k - 1]) % mod;
        return dp[x][y][stp];
    }
};




class Solution
{
    int dirs[4][2] = {{0, 1}, {0, -1}, {1, 0}, {-1, 0}}, mod = 1e9 + 7;

    int dfs(int m, int n, int i, int j, int k, vvv &dp)
    {
        if (!k)
            return 0;
        if (i < 0 || j < 0 || i >= m || j >= n)
            return 1;
        if (dp[i][j][k] != -1)
            return dp[i][j][k];

        int res = 0;
        for (auto [dx, dy] : dirs)
            res = (res + dfs(m, n, i + dx, j + dy, k - 1, dp)) % mod;
        return dp[i][j][k] = res;
    }

public:
    int findPaths(int m, int n, int k, int x, int y)
    {
        vvv dp(m, vv(n, vector<int>(k + 1, -1)));
        int ans = 0;
        for (auto [dx, dy] : dirs)
            ans = (ans + dfs(m, n, x + dx, y + dy, k, dp)) % mod;
        return ans;
    }
};

// @lc app=leetcode id=576 lang=cpp