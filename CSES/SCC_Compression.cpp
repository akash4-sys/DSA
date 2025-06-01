#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define II ({ int a; cin >> a; a; })

class SCC
{
    int n;
    vector<ll> wt, col;
    vector<vector<int>> g, rg;

public:
    SCC() {
        n = II;
        int m = II;
        wt.resize(n);
        for (ll &w : wt)
            w = II;
        
        col.resize(n, 0);
        g.resize(n);
        rg.resize(n);
        while (m--) {
            int u = II - 1, v = II - 1;
            g[u].push_back(v);
            rg[v].push_back(u);
        }
    }

    void Kosaraju()
    {
        vector<int> nodes;
        auto dfs = [&](auto &&dfs, int u) -> void {
            col[u] = 1;
            for (int v : g[u])
                if (!col[v])
                    dfs(dfs, v);
            nodes.push_back(u);
        };
        for (int i = 0; i < n; i++)
            if (!col[i])
                dfs(dfs, i);
        
        auto rdfs = [&](auto &&rdfs, int u, int c) -> void {
            col[u] = c;
            for (int v : rg[u])
                if (!col[v])
                    rdfs(rdfs, v, c);
        };
        
        int c = 1;
        col = vector<ll>(n, 0);
        while (!nodes.empty()) {
            int u = nodes.back();
            nodes.pop_back();
            if (!col[u])
                rdfs(rdfs, u, c), c++;
        }
    }

    int compressedG(vector<vector<int>> &G, vector<ll> &W) {
        Kosaraju();
        int k = *max_element(col.begin(), col.end()) + 1;
        vector<int> vis(n, 0);
        W.resize(k, 0LL);
        G.resize(k);

        auto dfs = [&](auto &&dfs, int u) -> void {
            if (vis[u])
                return;
            vis[u] = 1;
            W[col[u]] += wt[u];
            for (int &v : g[u]) {
                if (col[u] != col[v])
                    G[col[u]].push_back(col[v]);
                dfs(dfs, v);
            }
        };

        for (int u = 0; u < n; u++)
            dfs(dfs, u);
        return k;
    }
};

int main()
{
    SCC scc;
    vector<vector<int>> g;
    vector<ll> w;
    int k = scc.compressedG(g, w);
    vector<ll> coins(k, 0);

    auto dfs = [&](auto &&dfs, int u) -> ll {
        if (coins[u])
            return coins[u];
        coins[u] = w[u];
        for (int &v : g[u])
            coins[u] = max(coins[u], dfs(dfs, v) + w[u]);
        return coins[u];
    };

    ll ans = 0;
    for (int u = 1; u < k; u++)
        ans = max(ans, dfs(dfs, u));
    cout << ans;
    return 0;
}