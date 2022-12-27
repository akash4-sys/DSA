#include "../../headers.h"

class Solution
{
public:
    int numTilings(int n)
    {
        int mod = 1e9 + 7;
        vector<vector<int>> dp(n + 2, vector<int>(2, 0));
        dp[1] = {1, 1}, dp[2] = {2, 2};
        for (int i = 3; i <= n; i++)
        {
            dp[i][0] = (dp[i - 1][0] + dp[i - 2][0] + (2l * dp[i - 2][1])) % mod;
            dp[i][1] = (dp[i - 1][0] + dp[i - 1][1]) % mod;
        }
        return dp[n][0];
    }
};


class Solution
{
    const int mod = 1e9 + 7;
    long rc(int i, int n, int gap)
    {
        if (i > n)
            return 0;
        if (i == n)
            return !gap;
        if (gap)
            return (rc(i + 1, n, 0) + rc(i + 1, n, 1)) % mod;
        return (rc(i + 1, n, 0) + rc(i + 2, n, 0) + 2l * rc(i + 2, n, 1)) % mod;
    }

public:
    int numTilings(int n)
    {
        return rc(0, n, 0);
    }
};