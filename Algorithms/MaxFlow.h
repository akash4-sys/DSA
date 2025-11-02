#pragma once

#include <vector>
#include <queue>

using namespace std;

// @ Ford-Fulkerson method using edmond karp algorithm to find maximum flow in a directed graph
//  Time Complexity - O(VE^2)
//  Space Complexity - O(V^2)

#define ll long long

class EdmondKarp
{
    int n;
    vector<int> par;
    vector<vector<ll>> g, cap;

    ll reachable(int src, int dest)
    {
        queue<pair<int, ll>> q;
        q.push({src, LLONG_MAX});
        while (!q.empty())
        {
            auto [u, minFlow] = q.front();
            q.pop();
            if (u == dest)
                return max(minFlow, 0LL);
            for (auto &v : g[u])
                if (par[v] == -1 && cap[u][v]) {
                    par[v] = u;
                    q.push({v, min(minFlow, cap[u][v])});
                }
        }
        return 0;
    }

public:
    EdmondKarp(vector<vector<int>> &edges, int n) {
        this->n = n;
        cap.resize(n, vector<ll>(n, 0));
        g.resize(n);
        par.resize(n, -1);
        for (auto &e : edges) {
            g[e[0]].push_back(e[1]);
            g[e[1]].push_back(e[0]);
            cap[e[0]][e[1]] += e[2];

            // Min cut comes out to be wrong if i set backward edge capacity to zero why? It will give wrong answer for maxflow
            cap[e[1]][e[0]] += e[2];
        }
    }

    ll maxFlow(int src, int dest)
    {
        ll flow = 0, minFlow;
        while (minFlow = reachable(src, dest))
        {
            flow += minFlow;
            for (int u = dest; u != src; u = par[u]) {
                cap[par[u]][u] -= minFlow;
                cap[u][par[u]] += minFlow;
            }
            fill(par.begin(), par.end(), -1);
        }
        return flow;
    }

    vector<int> cutMinEdges(int src)
    {
        maxFlow(0, n - 1);
        vector<int> vis(n, 0), ans;
        auto dfs = [&](auto &&dfs, int u) -> void {
            vis[u] = 1;
            for (auto &v : g[u])
                if (!vis[v] && cap[u][v] > 0)
                    dfs(dfs, v);
        };
        dfs(dfs, src);

        for (int u = 0; u < n; u++)
            for (auto &v : g[u])
                if (vis[u] && !vis[v]) {
                    ans.emplace_back(u);
                    ans.emplace_back(v);
                }
        return ans;
    }
};