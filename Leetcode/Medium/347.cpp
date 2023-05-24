#include "../../headers.h"

class Solution
{
public:
    vector<int> topKFrequent(vector<int> &v, int k)
    {
        vector<int> ans;
        unordered_map<int, int> mp;
        for (int n : v)
            mp[n]++;
        
        vector<pair<int, int>> vp;
        for (auto [n, c] : mp)
            vp.push_back({c, n});
            
        sort(v.begin(), v.end(), greater<pair<int, int>>());
        for (int i = 0; i < k; i++)
            ans.push_back(vp[i].second);
        return ans;
    }
};