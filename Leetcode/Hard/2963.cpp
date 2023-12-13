#include "../../headers.h"

class Solution
{
public:
    int numberOfGoodPartitions(vector<int> &v)
    {
        int n = v.size(), ans = 1, mod = 1e9 + 7;
        unordered_map<int, int> mp;
        for (int i = 0; i < n; i++)
            mp[v[i]] = i;
        
        for (int i = 0, j = 0; i < n; i++)
        {
            ans = i > j ? (ans * 2) % mod : ans;
            j = max(j, mp[v[i]]);
        }
        return ans;
    }
};