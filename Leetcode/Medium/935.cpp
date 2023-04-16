#include "../../headers.h"

static int dir[8][2] = {{2, 1}, {2, -1}, {-2, 1}, {-2, -1}, {1, 2}, {1, -2}, {-1, 2}, {-1, -2}};
static int pad[4][3] = {{1, 2, 3}, {4, 5, 6}, {7, 8, 9}, {-1, 0, -1}};

class Solution
{
    int dp[5001][4][3], mod = 1e9 + 7;
    int dfs(int n, int i, int j)
    {
        if (i < 0 || j < 0 || i >= 4 || j >= 3 || pad[i][j] == -1)
            return 0;
        if (dp[n][i][j] != -1)
            return dp[n][i][j];
        if (!n)
            return 1;

        int res = 0;
        for (auto [dx, dy] : dir)
            res = (res + dfs(n - 1, i + dx, j + dy)) % mod;
        return dp[n][i][j] = res;
    }

public:
    int knightDialer(int n)
    {
        memset(dp, -1, sizeof(dp));
        int ans = 0;
        for (int i = 0; i < 4; i++)
            for (int j = 0; j < 3; j++)
                ans = (ans + dfs(n - 1, i, j)) % mod;
        return ans;
    }
};