#include "../../headers.h"

class Solution
{
public:
    int sumCounts(vector<int> &v)
    {
        int ans = 0;
        unordered_map<int, int> mp;
        for (int i = 0; i < v.size(); i++)
        {
            mp[v[i]]++;
            ans += (mp.size() * mp.size());
            auto tmp = mp;
            for (int j = 0; j < i; j++)
            {
                if (--tmp[v[j]] == 0)
                    tmp.erase(v[j]);
                ans += (tmp.size() * tmp.size());
            }
        }
        return ans;
    }
};