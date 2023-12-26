#include "../../headers.h"

class Solution
{
public:
    int checkWays(vector<vector<int>> &edges)
    {
        unordered_set<int> vis;
        unordered_map<int, unordered_set<int>> g;
        for (auto &e : edges)
        {
            g[e[0]].insert(e[1]);
            g[e[1]].insert(e[0]);
        }

        int n = g.size(), ans = 1;
        priority_queue<pair<int, int>> pq;
        for (auto &[u, v] : g)
            pq.push({v.size(), u});
        
        while (!pq.empty())
        {
            auto [d, u] = pq.top();
            pq.pop();

            int par = -1, pardeg = INT_MAX;
            for (int v : g[u])
                if (vis.count(v) && g[v].size() < pardeg && g[v].size() >= d)
                    par = v, pardeg = g[v].size();
            vis.insert(u);

            if (par == -1)
            {
                if (d != n - 1)
                    return 0;
                continue;
            }

            for (int v : g[u])
                if (par != v && !g[par].count(v))
                    return 0;
            if (d == pardeg)
                ans = 2;
        }
        return ans;
    }
};