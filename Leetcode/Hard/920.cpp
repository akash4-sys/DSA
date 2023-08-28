#include "../../headers.h"

class Solution
{
public:
    int numMusicPlaylists(int n, int m, int k)
    {
        int mod = 1e9 + 7;
        vector dp(n + 1, vector<long long>(m + 1, 0));
        dp[0][0] = 1;
        for (int i = 1; i <= n; i++)
            for (int j = 1; j <= m; j++)
                dp[i][j] = ((dp[i - 1][j - 1] * i) + (dp[i][j - 1] * max(0, i - k))) % mod;
        return dp[n][m];
    }
};



class Solution
{
    int mod = 1e9 + 7, dp[101][101];
    long long rec(int n, int m, int k)
    {
        if (!n && !m)
            return 1;
        if (!n || !m)
            return 0;
        if (dp[n][m] != -1)
            return dp[n][m];

        long long take = (rec(n - 1, m - 1, k) * n) % mod;
        long long notake = (rec(n, m - 1, k) * max(0, n - k)) % mod;
        return dp[n][m] = (take + notake) % mod;
    }

public:
    int numMusicPlaylists(int n, int m, int k)
    {
        memset(dp, -1, sizeof(dp));
        return rec(n, m, k);
    }
};