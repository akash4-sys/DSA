#include "../../headers.h"

#define ll long long
#define p pair<ll, int>

class Solution
{
    void minDistance(int n, vector<vector<p>> &adj, int src, vector<ll> &dist)
    {
        priority_queue<p, vector<p>, greater<p>> pq;
        pq.push({0, src});
        dist[src] = 0;
        while (!pq.empty())
        {
            auto [w, u] = pq.top();
            pq.pop();
            if (dist[u] != w)
                continue;
            for (auto [v, wt] : adj[u])
                if (w + wt < dist[v])
                    dist[v] = w + wt, pq.push({dist[v], v});
        }
    }

public:
    long long minimumWeight(int n, vector<vector<int>> &edges, int s1, int s2, int dest)
    {
        vector<vector<p>> g(n), rg(n);
        for (auto e : edges)
        {
            g[e[0]].push_back({e[1], e[2]});
            rg[e[1]].push_back({e[0], e[2]});
        }

        ll ans = LLONG_MAX, MAX = 1e10;
        vector<ll> s1d(n, MAX), s2d = s1d, dd = s1d;
        minDistance(n, g, s1, s1d);
        minDistance(n, g, s2, s2d);
        minDistance(n, rg, dest, dd);

        if (dd[s1] == MAX || dd[s2] == MAX)
            return -1;

        for (int i = 0; i < n; i++)
            ans = min(ans, dd[i] + s1d[i] + s2d[i]);
        return ans;
    }
};