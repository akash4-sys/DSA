#include "headers.h"

#define p pair<int, int>
class Graph
{
    int n;
    vector<vector<p>> adj;
public:
    Graph(int n, vector<vector<int>> &edges)
    {
        this->n = n;
        adj = vector<vector<p>>(n);
        for (auto e : edges)
            adj[e[0]].push_back({e[1], e[2]});
    }

    void addEdge(vector<int> e)
    {
        adj[e[0]].push_back({e[1], e[2]});
    }

    int shortestPath(int src, int dest)
    {
        priority_queue<p, vector<p>, greater<p>> pq;
        vector<int> vis(n, 0), dist(n, INT_MAX);
        pq.push({0, src});
        dist[src] = 0;

        while (!pq.empty())
        {
            auto [w, u] = pq.top();
            pq.pop();
            if (u == dest)
                return dist[u];
            vis[u] = 1;
            for (auto [v, wt] : adj[u])
                if (!vis[v] && dist[u] + wt < dist[v])
                    dist[v] = dist[u] + wt, pq.push({dist[v], v});   
        }
        return -1;
    }
};