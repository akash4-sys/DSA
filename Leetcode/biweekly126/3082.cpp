#include "../../headers.h"

class Solution
{
public:
    int sumOfPower(vector<int> &v, int k)
    {
        int mod = 1e9 + 7, dp[101] = {0};
        dp[0] = 1;
        for (int a : v)
            for (int sum = k; sum; sum--)
                dp[sum] = (dp[sum] * 2 % mod + (sum >= a ? dp[sum - a] : 0)) % mod;
        return dp[k];
    }
};



class Solution
{
    int dp[101][101], mod = 1e9 + 7;

    long long power(long long a, long long b)
    {
        long long res = 1;
        for (a %= mod; b > 0; b >>= 1)
        {
            if (b & 1)
                res = (res * a) % mod;
            a = (a * a) % mod;
        }
        return res;
    }

    long long rec(vector<int> &v, int i, int k)
    {
        if (k == 0)
            return power(2, v.size() - i);
        if (i == v.size())
            return 0;
        if (dp[i][k] != -1)
            return dp[i][k];

        int take = k >= v[i] ? rec(v, i + 1, k - v[i]) : 0;
        return dp[i][k] = (rec(v, i + 1, k) * 2 + take) % mod;
    }

public:
    int sumOfPower(vector<int> &v, int k)
    {
        memset(dp, -1, sizeof(dp));
        return rec(v, 0, k);
    }
};