#include "../../headers.h"

class Solution
{
public:
    int findMaximumLength(vector<int> &v)
    {
        int n = v.size();
        vector<long long> pf(n + 1, 0);
        for (int i = 1; i <= n; i++)
            pf[i] += pf[i - 1] + v[i - 1];
        
        vector<pair<int, int>> dp(n + 1, {1, 1});
        for (int i = 1; i <= n; i++)
        {
            dp[i] = max(dp[i], dp[i - 1]);
            auto [len, j] = dp[i];
            long long lastsum = pf[i] - pf[j - 1];
            int nxt_idx = lower_bound(pf.begin(), pf.end(), lastsum + pf[i]) - pf.begin();
            if (nxt_idx <= n)
                dp[nxt_idx] = max(dp[nxt_idx], {len + 1, i + 1});
        }
        return dp[n].first;
    }
};