#include "../../headers.h"

class Solution
{
public:
    int minimumOperationsToMakeKPeriodic(string &s, int k)
    {
        int n = s.size(), ans = 0;
        unordered_map<string, int> mp;
        for (int i = 0; i < n; i += k)
            mp[s.substr(i, k)]++;

        for (auto it : mp)
            ans = max(ans, it.second);
        return (n / k) - ans;
    }
};