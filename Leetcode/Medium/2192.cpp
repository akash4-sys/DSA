#include "../../headers.h"
// @lc app=leetcode id=2192 lang=cpp

class Solution
{
    void dfs(vector<vector<int>> &g, vector<vector<int>> &ans, int src, int v)
    {
        for(auto c: g[v])
            if(ans[c].empty() || ans[c].back() != src)
                ans[c].push_back(src), dfs(g, ans, src, c);
    }
public:
    vector<vector<int>> getAncestors(int n, vector<vector<int>> &edges)
    {
        vector<vector<int>> g(n), ans(n);
        for (auto e : edges)
            g[e[0]].push_back(e[1]);
        for (int i = 0; i < n; i++)
            dfs(g, ans, i, i);
        return ans;
    }
};

