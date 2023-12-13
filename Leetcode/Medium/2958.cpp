#include "../../headers.h"

class Solution
{
public:
    int maxSubarrayLength(vector<int> &v, int k)
    {
        unordered_map<int, int> mp;
        int ans = 0;
        for (int l = 0, r = 0; r < v.size(); r++)
        {
            mp[v[r]]++;
            while (l <= r && mp[v[r]] > k)
                --mp[v[l++]];
            ans = max(ans, r - l + 1);
        }
        return ans;
    }
};