#include "../../headers.h"

// Time Complexity - O(2^N * N^2*LogN)
// Space Complexity - O(N^2)

#define p pair<int, int>

class Solution
{
    int maxDist(vector<vector<p>> &adj, int n, int src, int mask)
    {
        priority_queue<p, vector<p>, greater<p>> pq;
        vector<int> vis(n, 1), dist(n, INT_MAX);

        int res = 0, cnt = 0;
        for (int i = 0; i < n; i++)
            if (mask & (1 << i))
                vis[i] = 0, cnt++;

        pq.push({0, src});
        dist[src] = 0;
        while (!pq.empty())
        {
            auto [w, u] = pq.top();
            pq.pop();
            vis[u] = 1;
            for (auto [v, wt] : adj[u])
                if (!vis[v] && dist[u] + wt < dist[v])
                    dist[v] = dist[u] + wt, pq.push({dist[v], v});
        }

        for (int i = 0; i < n; i++)
            if (dist[i] != INT_MAX)
                res = max(res, dist[i]), cnt--;
        return cnt == 0 ? res : INT_MAX;
    }

public:
    int numberOfSets(int n, int mxdist, vector<vector<int>> &edges)
    {
        vector<vector<p>> adj(n);
        for (auto &e : edges)
        {
            adj[e[0]].push_back({e[1], e[2]});
            adj[e[1]].push_back({e[0], e[2]});
        }

        int totalSets = 1 << n, ans = 0;
        for (int i = 0; i < totalSets; i++)
        {   
            int res = 0;
            for (int j = 0; j < n; j++)
                if (i & (1 << j))
                {
                    res = max(res, maxDist(adj, n, j, i));
                    if (res > mxdist)
                        break;
                }
            ans += res <= mxdist;
        }
        return ans;
    }
};