#include "../../headers.h"

#define vec vector<int>
#define vv vector<vec>
#define vvp vector<vector<pair<int, int>>>

class Solution
{
    void fillG(vvp &adj, vv &edges, int col)
    {
        for (auto e : edges)
            adj[e[0]].push_back({e[1], col});
    }

public:
    vec shortestAlternatingPaths(int n, vv &r, vv &b)
    {
        queue<vec> q;
        vvp adj(n);
        vec dist(n, -1);
        fillG(adj, r, 1);
        fillG(adj, b, 0);
        q.push({0, 0, -1});

        while (!q.empty()) 
        {
            auto a = q.front();
            q.pop();
            int u = a[0], d = a[1], c = a[2];
            dist[u] = dist[u] != -1 ? dist[u] : d;
            for (auto &[v, col] : adj[u])
                if (v != -1 && c != col)
                    q.push({v, d + 1, col}), v = -1;
        }
        return dist;
    }
};