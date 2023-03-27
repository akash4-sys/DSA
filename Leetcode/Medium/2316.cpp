#include "../../headers.h"

class Solution
{
    int dfs(vector<vector<int>> &g, vector<int> &vis, int u)
    {
        vis[u] = 1;
        int ans = 1;
        for (int v : g[u])
            if (!vis[v])
                ans += dfs(g, vis, v);
        return ans;
    }

public:
    long long countPairs(int n, vector<vector<int>> &edges)
    {
        vector<vector<int>> g(n);
        vector<int> vis(n, 0);
        for (auto e : edges)
            g[e[0]].push_back(e[1]), g[e[1]].push_back(e[0]);
        
        long long total = n, ans = 0;
        for (int i = 0; i < n; i++)
            if (!vis[i])
            {
                int x = dfs(g, vis, i);
                ans += (x * (total - x));
                total -= x;
            }
        return ans;
    }
};