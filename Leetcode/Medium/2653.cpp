#include "headers.h"

class Solution
{
    int xthSmallest(map<int, int> &mp, int x)
    {
        for (auto [n, c] : mp)
        {
            if (x - c <= 0)
                return min(0, n);
            x -= c;
        }
        return 99;
    }

public:
    vector<int> getSubarrayBeauty(vector<int> &v, int k, int x)
    {
        map<int, int> mp;
        for (int i = 0; i < k; i++)
            mp[v[i]]++;
        
        vector<int> ans = {xthSmallest(mp, x)};
        for (int i = 1; i <= v.size() - k; i++)
        {
            mp[v[i - 1]]--;
            if (!mp[v[i - 1]])
                mp.erase(v[i - 1]);
            mp[v[i + k - 1]]++;
            ans.push_back(xthSmallest(mp, x));
        }
        return ans;
    }
};


class Solution
{
public:
    vector<int> getSubarrayBeauty(vector<int> &v, int k, int x)
    {
        multiset<int> st(v.begin(), v.begin() + k);
        int n = *next(st.begin(), x - 1);
        vector<int> ans = {min(0, n)};

        for (int i = 1; i <= v.size() - k; i++)
        {
            st.erase(st.lower_bound(v[i - 1]));
            st.insert(v[i + k - 1]);
            n = *next(st.begin(), x - 1);
            ans.push_back(min(0, n));
        }
        return ans;
    }
};