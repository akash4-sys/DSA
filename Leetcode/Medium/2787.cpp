#include "headers.h"

class Solution
{
public:
    int numberOfWays(int n, int x)
    {
        int dp[301] = {0}, mod = 1e9 + 7, v;
        for (int i = 1; (v = pow(i, x)) <= n; i++)
            for (int i = n; i >= v; i--)
                dp[i] = (dp[i] + dp[i - v]) % mod;
        return dp[n];
    }
};


class Solution
{
    int mod = 1e9 + 7;
    int dp[301][301];
    int rec(int x, int i, int sum)
    {
        if (sum == 0)
            return 1;
        if (sum < 0 || pow(i, x) > sum)
            return 0;
        if (dp[i][sum] != -1)
            return dp[i][sum];
        
        int take = rec(x, i + 1, sum - pow(i, x));
        int no = rec(x, i + 1, sum);
        return dp[i][sum] = (take + no) % mod;
    }

public:
    int numberOfWays(int n, int x)
    {
        memset(dp, -1, sizeof(dp));
        return rec(x, 1, n);
    }
};