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


class Solution
{
    int maskMaxVal[15] = {-1, -1, 3, -1, 15, -1, 63, -1, 255, -1, 1023, -1, 4095, -1, 16383};
    map<pair<int, int>, int> dp;
public:
    int maxScore(vector<int>& v, int it = 1, int mask = 0)
    {
        int n = v.size();
        if (maskMaxVal[n] == mask)
            return 0;
        if (dp.count({it, mask}))
            return dp[{it, mask}];

        int ans = 0;
        for (int i = 0; i < n; i++)
            for (int j = i + 1; j < n && !(mask & (1 << i)); j++)
                if (!(mask & (1 << j)))
                {
                    int newMask = mask | (1 << i) | (1 << j);
                    int score = gcd(v[i], v[j]) * it;
                    ans = max(ans, maxScore(v, it + 1, newMask) + score);
                }
        return dp[{it, mask}] = ans;
    }
};