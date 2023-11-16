#include "../../headers.h"

class Solution
{
public:
    vector<int> restoreArray(vector<vector<int>> &edges)
    {
        int u;
        unordered_map<int, vector<int>> mp;
        for (auto &e : edges)
            mp[e[0]].push_back(e[1]), mp[e[1]].push_back(e[0]);
        
        for (auto [n, v] : mp)
            u = (v.size() == 1) ? n : u;
        
        vector<int> ans;
        while (ans.size() <= edges.size())
        {
            int p = ans.size() ? ans.back() : 1e6;
            ans.push_back(u);
            u = mp[u][0] != p || mp[u].size() == 1 ? mp[u][0] : mp[u][1];
        }
        return ans;
    }
};