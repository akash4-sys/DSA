#include <bits/stdc++.h>
using namespace std;
#define ll long long

class EdmondKarp
{
    int n;
    vector<vector<ll>> g, cap;

    bool reachable(vector<int> &par, int src, int dest)
    {
        queue<int> q;
        q.push(src);
        while (!q.empty())
        {
            int u = q.front();
            q.pop();
            if (u == dest)
                return 1;
            for (auto &v : g[u])
                if (par[v] == -1 && cap[u][v] > 0)
                    par[v] = u, q.push(v);
        }
        return 0;
    }

public:
    ll maxFlow(vector<vector<int>> &edges, int n, int src, int dest)
    {
        this->n = n;
        cap.resize(n, vector<ll>(n, 0));
        g.resize(n);
        for (auto &e : edges) {
            g[e[0]].push_back(e[1]);
            g[e[1]].push_back(e[0]);
            cap[e[0]][e[1]] += e[2];
        }

        ll flow = 0;
        vector<int> par(n, -1);
        while (reachable(par, src, dest))
        {
            ll minFlow = LLONG_MAX;
            for (int u = dest; u != src; u = par[u])
                minFlow = min(minFlow, cap[par[u]][u]);
            
            flow += minFlow;
            for (int u = dest; u != src; u = par[u]) {
                cap[par[u]][u] -= minFlow;
                cap[u][par[u]] += minFlow;
            }
            fill(par.begin(), par.end(), -1);
        }
        return flow;
    }
};

int main()
{
    int n, m, u, v, w;
    cin >> n >> m;
    vector<vector<int>> edges;
    while (m--) {
        cin >> u >> v >> w;
        edges.push_back({u - 1, v - 1, w});
    }

    EdmondKarp e;
    cout << e.maxFlow(edges, n, 0, n - 1);
    return 0;
}