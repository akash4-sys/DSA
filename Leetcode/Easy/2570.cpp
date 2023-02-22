#include "headers.h"

class Solution
{
public:
    vector<vector<int>> mergeArrays(vector<vector<int>> &a, vector<vector<int>> &b)
    {
        map<int, int> mp;
        for (auto v : a)
            mp[v[0]] = v[1];
        for (auto v : b)
            mp[v[0]] += v[1];
        vector<vector<int>> ans;
        for (auto [n, c] : mp)
            ans.push_back({n, c});
        return ans;
    }
};