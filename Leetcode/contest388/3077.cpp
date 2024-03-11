#include "../../headers.h"

class Solution
{
    vector<vector<vector<long long>>> dp;
    long long rec(vector<int> &v, int i, long long k, int started)
    {
        if (!k)
            return 0;
        if (i == v.size())
            return k == 1 && started ? 0 : -1e15;
        if (dp[i][k][started] != -1e15)
            return dp[i][k][started];

        long long res = started ? rec(v, i, k - 1, 0) : rec(v, i + 1, k, 0);
        return dp[i][k][started] = max(res, rec(v, i + 1, k, 1) + ((k % 2 ? 1 : -1) * v[i] * k));
    }

public:
    long long maximumStrength(vector<int> &v, int k)
    {
        dp = vector(v.size(), vector(k + 1, vector<long long>(2, -1e15)));
        return rec(v, 0, k, 0);
    }
};