#include "../../headers.h"

class Solution
{
public:
    vector<int> findOriginalArray(vector<int> &v)
    {
        if(v.size() % 2)
            return {};

        map<int, int> mp;
        for(int n: v)
            mp[n]++;
        
        vector<int> ans;
        for(auto [x, y]: mp)
        {
            if(mp.count(x * 2) && mp[x] > mp[x * 2])
                return {};
            for(int i = 0; i < mp[x]; i++, mp[x * 2]--)
                ans.push_back(x);
        }
        return ans.size() == v.size() / 2 ? ans : ans = {};
    }
};