#include "../../headers.h"

class Solution
{
    vector<int> vis;
    void dfs(vector<vector<int>> &g, int u)
    {
        vis[u] = 1;
        for (int v : g[u])
            if (!vis[v])
                dfs(g, v);
    }

public:
    int makeConnected(int n, vector<vector<int>> &edges)
    {
        if (edges.size() < n - 1)
            return -1;
        
        vis = vector<int>(n, 0);
        vector<vector<int>> g(n);
        for (auto e : edges)
            g[e[0]].push_back(e[1]), g[e[1]].push_back(e[0]);
        
        int ans = -1;
        for (int i = 0; i < n; i++)
            if (!vis[i])
                dfs(g, i), ans++;
        return ans;
    }
};