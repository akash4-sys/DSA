#include "headers.h"

class Solution
{
    vector<vector<int>> comp;
    void dfs(vector<vector<int>> &g, vector<int> &vis, int u, int it)
    {
        if (it == comp.size())
            comp.push_back({});
        vis[u] = 1;
        comp[it].push_back(u);
        for (int i = 0; i < g.size(); i++)
            if (!vis[i] && g[u][i])
                dfs(g, vis, i, it);
    }

    int complete(vector<vector<int>> &g, vector<int> &v)
    {
        for (int i = 0; i < v.size(); i++)
            for (int j = i + 1; j < v.size(); j++)
                if (!g[v[i]][v[j]])
                    return 0;
        return 1;
    }

public:
    int countCompleteComponents(int n, vector<vector<int>> &edges)
    {
        vector<vector<int>> g(n, vector<int>(n, 0));
        vector<int> vis(n, 0);

        for (auto e : edges)
            g[e[0]][e[1]] = g[e[1]][e[0]] = 1;
        
        for (int u = 0, it = 0; u < n; u++)
            if (!vis[u]) {
                dfs(g, vis, u, it);
                it++;
            }
        
        int ans = 0;
        for (auto r : comp)
            ans += complete(g, r);
        return ans;
    }
};