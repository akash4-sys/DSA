#include "headers.h"

class Solution
{
    int p = 1e9 + 7;
    long long inv(long long x)
    {
        return x != 1 ? (p - (p / x)) * inv(p % x) % p : 1;
    }

public:
    int numberOfWays(int s, int t, int k)
    {
        if (abs(s - t) > k || (s - t - k) % 2)
            return 0;
        long long ans = 1;
        for (int i = 0; i < (t - s + k) / 2; i++)
            ans = (ans * (k - i) % p) * inv(i + 1) % p;
        return ans;
        // return nCr(k, (b - a + k) / 2);
    }
};

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

class Solution
{
    int dp[3000][1001], mod = 1e9 + 7;
    int dfs(int s, int t, int k)
    {
        if (!k)
            return s == t;
        if (dp[s + 1000][k] != -1)
            return dp[s + 1000][k];
        return dp[s + 1000][k] = (dfs(s + 1, t, k - 1) + dfs(s - 1, t, k - 1)) % mod;
    }

public:
    int numberOfWays(int s, int t, int k)
    {
        memset(dp, -1, sizeof(dp));
        return dfs(s, t, k);
    }
};