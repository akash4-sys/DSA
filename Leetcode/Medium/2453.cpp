#include "../../headers.h"

class Solution
{
public:
    int destroyTargets(vector<int> &v, int k)
    {
        int ans = INT_MAX, mx = INT_MIN;
        unordered_map<int, int> mp;
        for(auto n: v)
            mx = max(mx, ++mp[n % k]);
        for(auto n: v)
            if(mp[n % k] == mx)
                ans = min(ans, n);
        return ans;
    }
};