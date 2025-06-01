#pragma once

#include <vector>
#include <queue>

using namespace std;

class Dijkstra
{
public:
    vector<int> minDist(vector<vector<int>> &edges, int n, int src)
    {
        using p = pair<int, int>;
        priority_queue<p, vector<p>, greater<p>> pq;
        vector<vector<p>> adj(n);
        vector<int> dist(n, INT_MAX);

        for (auto e : edges)
            adj[e[0]].push_back({e[1], e[2]});

        pq.push({0, src});
        dist[src] = 0;

        while (!pq.empty())
        {
            auto [w, u] = pq.top();
            pq.pop();
            if (w != dist[u])
                continue;
            for (auto [v, wt] : adj[u])
                if (dist[u] + wt < dist[v])
                    dist[v] = dist[u] + wt, pq.push({dist[v], v});   
        }
        return dist;
    }
};