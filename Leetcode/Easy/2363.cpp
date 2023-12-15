#include "headers.h"

class Solution
{
public:
    vector<vector<int>> mergeSimilarItems(vector<vector<int>> &a, vector<vector<int>> &b)
    {
        vector<vector<int>> ans;
        map<int, int> mp;
        for (auto v : a)
            mp[v[0]] += v[1];
        for (auto v : b)
            mp[v[0]] += v[1];

        for (auto &[v, w] : mp)
            ans.push_back({v, w});
        return ans;
    }
};