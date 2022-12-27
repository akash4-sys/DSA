#pragma once

#include <vector>
#include <queue>

using namespace std;

class Dijkstra
{
public:
    int minDistance(vector<vector<int>> &edges, int n, int src)
    {
        using p = pair<int, int>;
        priority_queue<p, vector<p>, greater<p>> pq;
        vector<vector<p>> adj(n);
        vector<int> vis(n, 0), dist(n, INT_MAX);

        for (auto e : edges)
            adj[e[0]].push_back({e[1], e[2]});

        pq.push({0, src});
        dist[src] = 0;
        // dist[0] = -1; //depends if graph is 0 or 1 indexed, to avoid extra nodes

        while (!pq.empty())
        {
            auto [w, u] = pq.top();
            pq.pop();
            vis[u] = 1;
            for (auto [v, wt] : adj[u])
                if (!vis[v] && dist[u] + wt < dist[v])
                    dist[v] = dist[u] + wt, pq.push({dist[v], v});   
        }

        int minD = *max_element(dist.begin(), dist.end());
        return minD == INT_MAX ? -1 : minD;
    }
};