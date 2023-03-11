#include "headers.h"

#define ll long long
class Solution
{
    ll p[10] = {2, 3, 5, 7, 11, 13, 17, 19, 23, 29}, mod = 1e9 + 7;
    vector<vector<int>> dp;
    ll recurse(vector<int> &v, int i, int mask)
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
                return dp[i][mask] = recurse(v, i + 1, mask);
            m |= c ? 1 << j : c;
        }
        return dp[i][mask] = (recurse(v, i + 1, mask) + recurse(v, i + 1, m)) % mod;
    }

public:
    int squareFreeSubsets(vector<int> &v)
    {
        dp = vector<vector<int>>(1001, vector<int>(1024, -1));
        return 1LL * (recurse(v, 0, 0) - 1 + mod) % mod;
    }
};