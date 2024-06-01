#include "../../headers.h"

class Solution
{
    using p = pair<int, int>;
public:
    vector<int> minimumTime(int n, vector<vector<int>> &edges, vector<int> &dtime)
    {
        priority_queue<p, vector<p>, greater<p>> pq;
        vector<vector<p>> adj(n);
        vector<int> vis(n, 0), dist(n, INT_MAX);
        for (auto e : edges)
        {
            adj[e[0]].push_back({e[1], e[2]});
            adj[e[1]].push_back({e[0], e[2]});
        }

        pq.push({0, 0});
        dist[0] = 0;
        while (!pq.empty())
        {
            auto [w, u] = pq.top();
            pq.pop();
            vis[u] = 1;

            if (w >= dist[u])
                for (auto [v, wt] : adj[u])
                    if (!vis[v] && dist[u] + wt < min(dist[v], dtime[v]))
                        dist[v] = dist[u] + wt, pq.push({dist[v], v});
        }

        for (int &d : dist)
            d = d == INT_MAX ? -1 : d;
        return dist;
    }
};