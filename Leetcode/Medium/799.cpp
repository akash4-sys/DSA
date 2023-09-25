#include "../../headers.h"

class Solution
{
public:
    double champagneTower(int n, int x, int y)
    {
        vector dp(100, vector<double>(100, 0));
        dp[0][0] = n * 1.0;
        for (int i = 0; i <= x; i++)
            for (int j = 0; j <= i; j++)
            {
                double excess = (dp[i][j] - 1.0) / 2.0;
                dp[i + 1][j] += excess > 0 ? excess : 0;
                dp[i + 1][j + 1] += excess > 0 ? excess : 0;
            }
        return min(dp[x][y], 1.0);
    }
};