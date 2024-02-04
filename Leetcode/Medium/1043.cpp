#include "../../headers.h"

class Solution
{
public:
    int maxSumAfterPartitioning(vector<int> &v, int k)
    {
        int n = v.size();
        vector<int> dp(n + 1, 0);
        for (int i = 0; i < n; i++)
            for (int j = i, x = 0; j >= max(i - k + 1, 0); j--) {
                x = max(x, v[j]);
                dp[i + 1] = max(dp[i + 1], (i - j + 1) * x + dp[j]);
            }
        return dp[n];
    }
};


class Solution
{
    long long dp[501];
    long long rec(vector<int> &v, int k, int i)
    {
        if (i == v.size())
            return 0;
        if (dp[i] != -1)
            return dp[i];
        
        long long res = 0, mx = 0;
        for (int j = i; j < min((int)v.size(), i + k); j++) {
            mx = max(mx, (long long)v[j]);
            res = max(res, rec(v, k, j + 1) + (mx * (j - i + 1)));
        }
        return dp[i] = res;
    }

public:
    int maxSumAfterPartitioning(vector<int> &v, int k)
    {
        memset(dp, -1, sizeof(dp));
        return rec(v, k, 0);
    }
};