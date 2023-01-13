#include "../../headers.h"

class Solution
{
    int dfs(vector<vector<int>> &g, vector<bool> &app, int par, int u)
    {
        int ans = 0, dist = 0;
        for (int v : g[u])
        {
            if (par == v)
                continue;
            dist = dfs(g, app, u, v);
            if (dist || app[v])
                ans += dist + 2;
        }
        return ans;
    }

public:
    int minTime(int n, vector<vector<int>> &edges, vector<bool> &app)
    {
        vector<vector<int>> g(n);
        for (auto e : edges)
            g[e[0]].push_back(e[1]), g[e[1]].push_back(e[0]);
        return dfs(g, app, 0, 0);
    }
};