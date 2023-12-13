#include "../../headers.h"

class Solution
{
    unordered_map<int, int> mp;
    int dfs(vector<vector<int>> &g, int u, int par)
    {
        int res = 1;
        for (int v : g[u])
            if (!mp.count(v) && v != par)
                res += dfs(g, v, u);
        return res;
    }

public:
    int reachableNodes(int n, vector<vector<int>> &edges, vector<int> &r)
    {
        for (int a : r)
            mp[a]++;
        
        vector<vector<int>> g(n);
        for (auto e : edges)
            g[e[1]].push_back(e[0]), g[e[0]].push_back(e[1]);
        return dfs(g, 0, -1);
    }
};