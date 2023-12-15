#include "headers.h"

class Solution
{
public:
    long long countBadPairs(vector<int> &v)
    {
        long long ans = 0, n = v.size();
        unordered_map<int, int> mp;
        for (int i = 0; i < n; i++)
            v[i] -= i, mp[v[i]]++;
        
        for (int i = 0; i < n; i++)
            ans += ((n - i) - mp[v[i]]), mp[v[i]]--;
        return ans;
    }
};