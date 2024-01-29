#include "../../headers.h"

class Solution {
public:
    int kInversePairs(int n, int k)
    {
        if (k > n * (n - 1) / 2)
            return 0;

        int mod = 1e9 + 7;
        vector dp(2, vector<long>(k + 1, 0));
        dp[0][0] = 1;
        for (int i = 1; i <= n; i++)
            for (int j = 0; j <= k; j++)
            {
                dp[i % 2][j] = (dp[(i - 1) % 2][j] + (j ? dp[i % 2][j - 1] : 0)) % mod;
                if (j >= i)
                    dp[i % 2][j] = (dp[i % 2][j] - dp[(i - 1) % 2][j - i] + mod) % mod;
            }
        return dp[n % 2][k];
    }
};