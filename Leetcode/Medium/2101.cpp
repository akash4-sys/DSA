#include "../../headers.h"

class Solution
{
    int dfs(vector<vector<int>> &g, vector<int> &vis, int u)
    {
        vis[u] = 1;
        int res = 1;
        for (int v : g[u])
            if (!vis[v])
                res += dfs(g, vis, v);
        return res;
    }

public:
    int maximumDetonation(vector<vector<int>> &v)
    {
        vector<vector<int>> g(v.size());
        for (int i = 0; i < g.size(); i++)
            for (int j = 0; j < g.size(); j++)
            {
                long long x1 = v[i][0], y1 = v[i][1], x2 = v[j][0], y2 = v[j][1], r = v[i][2];
                if ((x1 - x2) * (x1 - x2) + (y1 - y2) * (y1 - y2) <= r * r)
                    g[i].push_back(j);
            }
        
        int ans = 0;
        for (int u = 0; u < v.size(); u++)
        {
            vector<int> vis(v.size(), 0);
            ans = max(ans, dfs(g, vis, u));
        }
        return ans;
    }
};