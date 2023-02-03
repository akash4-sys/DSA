#include "../../headers.h"

class Solution
{
    int dp[8][16384] = {0};
public:
    int maxScore(vector<int> &v, int it = 1, int mask = 0)
    {
        if (it > v.size() / 2)
            return 0;
        if (dp[it][mask])
            return dp[it][mask];
        for (int i = 0; i < v.size(); i++)
            for (int j = i + 1; j < v.size(); j++)
            {
                int m = (1 << i) + (1 << j);
                if (!(mask & m))
                    dp[it][mask] = max(dp[it][mask], it * gcd(v[i], v[j]) + maxScore(v, it + 1, m | mask));
            }
        return dp[it][mask];
    }
};