#include "../../headers.h"

class Solution
{
public:
    long long maximumSubarraySum(vector<int> &v, int k)
    {
        long long n = v.size(), ans = LLONG_MIN;
        vector<long long> pf(n);
        unordered_map<long long, vector<int>> mp;
        for (int i = 0; i < n; i++)
        {
            pf[i] = i ? pf[i - 1] + v[i] : v[i];
            mp[v[i]].push_back(i);
        }

        auto maxSum = [&](int i, int val) {
            if (mp.count(val))
                for (int j : mp[val]) {
                    int l = min(i, j), r = max(i, j);
                    ans = max(ans, pf[r] - (l ? pf[l - 1] : 0));
                }
        };

        for (int i = 0; i < n; i++)
            maxSum(i, v[i] + k), maxSum(i, v[i] - k);
        return ans == LLONG_MIN ? 0 : ans;
    }
};