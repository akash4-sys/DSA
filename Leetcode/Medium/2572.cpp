#include "headers.h"

class Solution
{
    int p[10] = {2, 3, 5, 7, 11, 13, 17, 19, 23, 29}, mod = 1e9 + 7;
    int sol(vector<int> &v, vector<vector<int>> &dp, int i, int mask)
    {
        if (i == v.size())
            return 1;
        if (dp[i][mask] != -1)
            return dp[i][mask];

        int m = mask;
        for (int j = 0; j < 10; j++)
        {
            int c = 0;
            for (int n = v[i]; n % p[j] == 0; n /= p[j], c++);
            if (c >= 2 || (c == 1 && (mask >> j) & 1))
                return dp[i][mask] = sol(v, dp, i + 1, mask);
            if (c)
                m |= (1 << j);
        }
        return dp[i][mask] = (sol(v, dp, i + 1, mask) + sol(v, dp, i + 1, m)) % mod;
    }

public:
    int squareFreeSubsets(vector<int> &v)
    {
        vector<vector<int>> dp(1001, vector<int>(1024, -1));
        return sol(v, dp, 0, 0) - 1;
    }
};