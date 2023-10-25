#include "../../headers.h"

// Time Complexity - O(K^2)
// Space Complexity - O(K)

class Solution
{
public:
    int numWays(int k, int n)
    {
        int mod = 1e9 + 7, m = min(k / 2 + 1, n);
        vector<int> dp1(m + 2, 0), dp2(m + 2);
        dp1[1] = 1;
        while (k--)
        {
            for (int i = 1; i <= m; i++)
                dp2[i] = ((long)dp1[i] + dp1[i - 1] + dp1[i + 1]) % mod;
            dp1 = dp2;
        }
        return dp1[0];
    }
};

// Time Complexity - O(K^2)
// Space Complexity - O(K^2)

class Solution
{
    int mod = 1e9 + 7, dp[501][501];
    int rec(int n, int k, int i)
    {
        if (k == 0)
            return i == 0;
        if (dp[k][i] != -1)
            return dp[k][i];
        
        int res = 0;
        if (i + 1 < n)
            (res += rec(n, k - 1, i + 1)) %= mod;
        if (i > 0)
            (res += rec(n, k - 1, i - 1)) %= mod;
        return dp[k][i] = (res + rec(n, k - 1, i)) % mod;
    }

public:
    int numWays(int k, int n)
    {
        memset(dp, -1, sizeof(dp));
        return rec(n, k, 0);
    }
};