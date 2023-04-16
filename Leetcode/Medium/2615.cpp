#include "headers.h"

class Solution
{
public:
    vector<long long> distance(vector<int> &v)
    {
        vector<long long> ans(v.size(), 0);
        unordered_map<int, long long> l, r, cl, cr;
        for (int i = 0; i < v.size(); i++)
        {
            ans[i] = (i * cl[v[i]]) - l[v[i]];
            l[v[i]] += i;
            cl[v[i]]++;
        }

        for (int i = v.size() - 1; i >= 0; i--)
        {
            ans[i] += r[v[i]] - (i * cr[v[i]]);
            r[v[i]] += i;
            cr[v[i]]++;
        }
        return ans;
    }
};

// Time Complexity - O(N)
// Space Complexity - O(N)

class Solution
{
public:
    vector<long long> distance(vector<int> &v)
    {
        vector<long long> ans(v.size(), 0), ind = ans;
        unordered_map<int, vector<long long>> mp;

        for (int i = 0; i < v.size(); i++)
        {
            long long x = mp[v[i]].size() ? mp[v[i]].back() : 0;
            mp[v[i]].push_back(i + x);
            ind[i] = mp[v[i]].size() - 1;
        }

        for (int i = 0; i < v.size(); i++)
        {
            if (mp[v[i]].size() == 1)
                continue;
            long long j = ind[i], l = 0, r = 0;
            if (j - 1 >= 0)
                l = (i * j) - mp[v[i]][j - 1];
            r = (mp[v[i]].back() - mp[v[i]][j]) - ((mp[v[i]].size() - j - 1) * i);
            ans[i] = l + r;
        }
        return ans;
    }
};