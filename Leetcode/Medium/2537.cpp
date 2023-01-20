#include "headers.h"

class Solution
{
public:
    long long countGood(vector<int> &v, int k)
    {
        long long ans = 0;
        unordered_map<int, int> mp;
        for (int l = 0, r = 0; r < v.size(); r++)
        {
            k -= mp[v[r]]++;
            while (k <= 0)
                k += --mp[v[l++]];
            ans += l;
        }
        return ans;
    }
};