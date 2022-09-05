#include "headers.h"

class Solution
{
    int dp[1000][1001] = {}, mod = 1e9 + 7;
    int dfs(int d, int k)
    {
        if (d >= k)
            return d == k;
        if (dp[d][k] == 0)
            dp[d][k] = (1 + dfs(d + 1, k - 1) + dfs(d + (d ? -1 : 1), k - 1)) % mod;
        return dp[d][k] - 1;
    }

public:
    int numberOfWays(int startPos, int endPos, int k)
    {
        return dfs(abs(startPos - endPos), k);
    }
};