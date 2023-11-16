#include "../../headers.h"

class Solution
{
public:
    int distributeCandies(int n, int limit)
    {
        vector<int> dp(n + 1, 0);
        dp[0] = 1;
        for (int child = 0; child < 3; ++child)
        {
            vector<int> t(n + 1, 0);
            for (int i = 0; i <= n; ++i)
                for (int j = 0; j <= min(limit, n - i); ++j)
                    t[i + j] += dp[i];
            dp = t;
        }
        return dp[n];
    }
};