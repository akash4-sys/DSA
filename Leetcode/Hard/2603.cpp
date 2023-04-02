#include "../../headers.h"

class Solution
{
public:
    int collectTheCoins(vector<int> &c, vector<vector<int>> &edges)
    {
        int n = c.size();
        vector<vector<int>> g(n);
        for (auto e : edges)
            g[e[0]].push_back(e[1]), g[e[1]].push_back(e[0]);
        
        vector<int> q, deg(n), steps(n, INT_MAX);
        for (int i = 0; i < n; i++)
        {
            deg[i] = g[i].size();
            if (deg[i] == 1)
                q.push_back(i);
        }

        while (!q.empty())
        {
            int u = q.back();
            q.pop_back();
            if (--steps[u] == 0)
                continue;
            n--;
            for (int v : g[u])
            {
                steps[v] = min({steps[v], steps[u], c[u] ? 2 : INT_MAX});
                if (--deg[v] == 1)
                    q.push_back(v);
            }
        }
        return max(0, n - 1) * 2;
    }
};