#include "headers.h"

#define p pair<int, int>

class Solution
{
    vector<int> shortestDist(vector<vector<p>> &adj, int n, int src)
    {
        priority_queue<p, vector<p>, greater<p>> pq;
        vector<int> vis(n, 0), dist(n, INT_MAX);
        pq.push({0, src});
        dist[src] = 0;

        while (!pq.empty())
        {
            auto [w, u] = pq.top();
            pq.pop();
            vis[u] = 1;
            for (auto [v, cw] : adj[u])
                if (!vis[v] && w + cw < dist[v])
                    dist[v] = w + cw, pq.push({dist[v], v});
        }
        return dist;
    }

    vector<vector<int>> setMaxWeight(vector<vector<int>> &edges, int it)
    {
        for (int i = it + 1; i < edges.size(); i++)
            edges[i][2] = edges[i][2] == -1 ? 2e9 : edges[i][2];
        return edges;
    }

public:
    vector<vector<int>> modifiedGraphEdges(int n, vector<vector<int>> &edges, int src, int dest, int t)
    {
        vector<vector<p>> adj(n);
        for (auto e : edges)
            if (e[2] != -1)
            {
                adj[e[0]].push_back({e[1], e[2]});
                adj[e[1]].push_back({e[0], e[2]});
            }
        
        auto dist = shortestDist(adj, n, src);
        if (dist[dest] < t)
            return {};
        
        if (dist[dest] == t)
            return setMaxWeight(edges, -1);

        for (int i = 0; i < edges.size(); i++)
        {
            int u = edges[i][0], v = edges[i][1];
            if (edges[i][2] != -1)
                continue;

            edges[i][2] = 1;
            adj[u].push_back({v, 1});
            adj[v].push_back({u, 1});
            dist = shortestDist(adj, n, src);

            if (dist[dest] > t)
                continue;

            edges[i][2] += (t - dist[dest]);
            return setMaxWeight(edges, i);
        }
        return {};
    }
};