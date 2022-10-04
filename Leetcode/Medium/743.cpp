#include "../../headers.h"

// using keyword
// Dijkstra''s Algorithm

class Solution
{
public:
    int networkDelayTime(vector<vector<int>> &edges, int n, int k)
    {
        using p = pair<int, int>;
        priority_queue<p, vector<p>, greater<p>> pq;
        vector<vector<p>> g(n + 1);
        vector<int> vis(n + 1, 0), dist(n + 1, INT_MAX);

        for (auto e : edges)
            g[e[0]].push_back({e[1], e[2]});

        pq.push({0, k});
        dist[0] = -1;
        dist[k] = 0;
        while (!pq.empty())
        {
            auto [w, v] = pq.top();
            pq.pop();
            vis[v] = 1;
            if (dist[v] < w)
                continue;
            for (auto &[c, cw] : g[v])
                if (!vis[c] && dist[v] + cw < dist[c])
                    dist[c] = dist[v] + cw, pq.push({dist[c], c});
        }
        int ans = *max_element(dist.begin(), dist.end());
        return ans == INT_MAX ? -1 : ans;
    }
};



// Floyd Warshall algorithm
// Time complexity - O(N^3)
// Space complexity - O(N^2)

class Solution
{
public:
    int networkDelayTime(vector<vector<int>> &edges, int n, int k)
    {
        vector<vector<long>> g(n, vector<long>(n, INT_MAX));
        for(auto &e: edges)
            g[e[0] - 1][e[1] - 1] = e[2];
        for(int i = 0; i < n; i++)
            g[i][i] = 0;
        
        for(int k = 0; k < n; k++)
            for(int i = 0; i < n; i++)
                for(int j = 0; j < n; j++)
                    g[i][j] = min(g[i][j], g[i][k] + g[k][j]);
        
        long ans = INT_MIN;
        for(int i = 0; i < n; i++)
        {
            if(g[k - 1][i] == INT_MAX)
                return -1;
            ans = max(ans, g[k - 1][i]); 
        }
        return int(ans);
    }
};