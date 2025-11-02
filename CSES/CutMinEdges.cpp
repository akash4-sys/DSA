#include <bits/stdc++.h>
using namespace std;
#define ll long long

// This is not logically correct but working
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

            // Min cut comes out to be wrong if i set backward edge capacity to zero why?
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
 
int main()
{
    int n, m, u, v, w = 1;
    cin >> n >> m;
    vector<vector<int>> edges;
    while (m--) {
        cin >> u >> v;
        edges.push_back({u - 1, v - 1, w});
    }
 
    EdmondKarp e(edges, n);
    auto a = e.cutMinEdges(0);
    cout << a.size() / 2 << endl;
    for (int i = 0; i < a.size(); i += 2)
        cout << a[i] + 1 << " " << a[i + 1] + 1 << "\n";
    return 0;
}