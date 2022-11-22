#include "../../headers.h"
#include "../../treestructure.h"

class Solution
{
public:
    int numSquares(int n)
    {
        vector<int> dp(n + 1, INT_MAX);
        dp[0] = 0;
        for (int i = 1; i <= n; i++)
            for (int j = 1; j * j <= n && i >= j * j; j++)
                dp[i] = min(dp[i], dp[i - (j * j)] + 1);
        return dp[n] == INT_MAX ? -1 : dp[n];
    }
};