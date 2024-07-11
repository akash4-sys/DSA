#include "../../headers.h"

class Solution
{
    map<int, int> mp;
    long long dp[100001];
    long long rec(vector<int> &v, int i)
    {
        if (i == v.size())
            return 0;
        if (dp[i] != -1)
            return dp[i];
        
        int take = v[i] * mp[v[i]];
        int j = upper_bound(v.begin(), v.end(), v[i] + 2) - v.begin();
        return dp[i] = max(rec(v, i + 1), rec(v, j) + take);
    }

public:
    long long maximumTotalDamage(vector<int> &v)
    {
        for (auto &x : v)
            mp[x]++;

        sort(v.begin(), v.end());
        auto it = unique(v.begin(), v.end());
        v.resize(distance(v.begin(), it));
        memset(dp, -1, sizeof(dp));
        return rec(v, 0);
    }
};