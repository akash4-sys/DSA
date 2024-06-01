#include "../../headers.h"

// This solution tracks the distance itself to backtrack the path
// ! probably won't work for negative weighted edges

class Solution
{
public:
    vector<bool> findAnswer(int n, vector<vector<int>> &e)
    {
        int m = e.size();
        using p = pair<int, int>;
        priority_queue<p, vector<p>, greater<p>> pq;
        vector<vector<p>> adj(n);
        vector<int> dist(n, INT_MAX);
        vector<bool> ans(m, 0);

        for (int i = 0; i < m; i++) {
            adj[e[i][0]].push_back({e[i][1], i});
            adj[e[i][1]].push_back({e[i][0], i});
        }

        pq.push({0, 0});
        dist[0] = 0;
        while (!pq.empty())
        {
            auto [w, u] = pq.top();
            pq.pop();
            if (dist[u] == w)
                for (auto [v, i] : adj[u])
                    if (w + e[i][2] < dist[v])
                        dist[v] = w + e[i][2], pq.push({dist[v], v});
        }

        pq.push({dist[n - 1], n - 1});
        while (!pq.empty())
        {
            auto [w, u] = pq.top();
            pq.pop();
            for (auto [v, i] : adj[u])
                if (w - e[i][2] == dist[v])
                    ans[e[i][2]] = 1, pq.push({dist[v], v});
        }
        return ans;
    }
};



// dijkstra track all shortest paths

class Solution
{
    using p = pair<int, int>;
    void dfs(vector<vector<vector<int>>> &adj, vector<bool> &ans, int u)
    {
        if (u == 0)
            return;
        for (auto &pa : adj[u]) {
            ans[pa[1]] = 1;
            dfs(adj, ans, pa[0]);
        }
    }

public:
    vector<bool> findAnswer(int n, vector<vector<int>> &e)
    {
        int m = e.size();
        priority_queue<p, vector<p>, greater<p>> pq;
        vector<vector<vector<int>>> adj(n), radj(n);
        vector<int> dist(n, INT_MAX);
        vector<bool> ans(m, 0);

        for (int i = 0; i < m; i++) {
            adj[e[i][0]].push_back({e[i][1], e[i][2], i});
            adj[e[i][1]].push_back({e[i][0], e[i][2], i});
        }

        pq.push({0, 0});
        dist[0] = 0;
        while (!pq.empty())
        {
            auto [w, u] = pq.top();
            pq.pop();
            for (auto &a : adj[u])
            {
                int v = a[0], wt = a[1], edge_idx = a[2];
                if (radj[v].empty() || radj[v].back()[0] != u)
                {
                    if (dist[u] + wt < dist[v])
                        radj[v].clear();
                    if (dist[u] + wt <= dist[v])
                    {
                        dist[v] = dist[u] + wt;
                        pq.push({dist[v], v});
                        radj[v].push_back({u, edge_idx});
                    }
                }
            }
        }
        dfs(radj, ans, n - 1);
        return ans;
    }
};