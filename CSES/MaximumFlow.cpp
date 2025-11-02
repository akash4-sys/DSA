#include <bits/stdc++.h>
using namespace std;
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
    ll maxFlow(vector<vector<int>> &edges, int n, int src, int dest)
    {
        this->n = n;
        cap.resize(n, vector<ll>(n, 0));
        g.resize(n);
        par.resize(n, -1);
        for (auto &e : edges) {
            g[e[0]].push_back(e[1]);
            g[e[1]].push_back(e[0]);
            cap[e[0]][e[1]] += e[2];
        }

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