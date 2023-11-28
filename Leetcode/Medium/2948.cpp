#include "../../headers.h"

class Solution
{
    void update(vector<int> &ans, vector<int> &idx, vector<int> &val)
    {
        sort(idx.begin(), idx.end());
        for (int i = 0; i < idx.size(); i++)
            ans[idx[i]] = val[i];
        idx.clear();
        val.clear();
    }

public:
    vector<int> lexicographicallySmallestArray(vector<int> &v, int k)
    {
        multimap<int, int> mp;
        for (int i = 0; i < v.size(); i++)
            mp.insert({v[i], i});
        
        vector<int> ans(v.size(), 0), idx, val;
        int p = mp.begin()->first;
        for (auto [n, i] : mp)
        {
            if (n - p > k)
                update(ans, idx, val);
            idx.push_back(i);
            val.push_back(n);
            p = n;
        }
        update(ans, idx, val);
        return ans;
    }
};