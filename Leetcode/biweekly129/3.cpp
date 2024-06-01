#include "../../headers.h"

class Solution
{
public:
    int numberOfStableArrays(int zero, int one, int limit)
    {
        int mod = 1e9 + 7;
        vector dp(zero + 1, vector(one + 1, vector<long long>(2, 0)));
        dp[0][0][1] = dp[0][0][0] = 1;
        for (int i = 0; i <= zero; i++)
            for (int j = 0; j <= one; j++)
                for (int p = 0; p < 2; p++)
                    for (int k = 1, u = p ? i : j; k <= min(u, limit); k++)
                        (dp[i][j][p] += dp[i - (p ? k : 0)][j - (p ? 0 : k)][!p]) %= mod;
        return (dp[zero][one][0] + dp[zero][one][1]) % mod;
    }
};