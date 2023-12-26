#include "../../headers.h"

class Solution
{
public:
    int minOperations(vector<int> &a, vector<int> &b)
    {
        unordered_map<int, int> mp;
        for (int i = 0; i < a.size(); i++)
            mp[a[i]] = i;

        vector<int> v;
        for (int x : b)
            if (mp.count(x))
            {
                if (v.empty())
                    v.push_back(mp[x]);
                int i = lower_bound(v.begin(), v.end(), mp[x]) - v.begin();
                mp[x] > v.back() ? v.push_back(mp[x]), 0 : v[i] = mp[x];
            }
        return v.size();
    }
};