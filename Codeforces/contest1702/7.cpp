#include <bits/stdc++.h>
using namespace std;

#define fast ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
#define II ({ int a; cin >> a; a; })

int n, maxDepth;
vector<int> depth;
vector<vector<int>> ancestor, g;

void dfs(int u, int par, int d) {
    ancestor[u][0] = par;
    depth[u] = d;
    for (int i = 1; i < maxDepth; i++)
        ancestor[u][i] = ancestor[ancestor[u][i - 1]][i - 1];
    for (int &v : g[u])
        if (v != par)
            dfs(v, u, d + 1);
}

void lcaPreprocess() {
    maxDepth = log2(n) + 1;
    ancestor.resize(n, vector<int>(maxDepth, -1));
    depth.resize(n, 0);
    dfs(0, 0, 0);
}

int lca(int u, int v) {
    if (depth[u] > depth[v])
            swap(u, v);

    for (int k = 0; (1 << k) <= depth[v] - depth[u]; k++)
        if ((1 << k) & depth[v] - depth[u])
            v = ancestor[v][k];

    for (int k = maxDepth - 1; k >= 0; k--)
        if (ancestor[u][k] != ancestor[v][k])
            u = ancestor[u][k], v = ancestor[v][k];
    return u == v ? u : ancestor[u][0];
}

bool query()
{
    int m = II, j = 0;
    vector<int> p(m), vis(m, 0);
    for (auto &u : p)
        u = II - 1;
    
    sort(p.begin(), p.end(), [&](int a, int b) {
        return depth[a] > depth[b];
    });

    auto checkPath = [&](int st) {
        for (int i = st; i < m; i++)
            if (lca(p[st], p[i]) == p[i])
                vis[i] = 1;
    };
    checkPath(0);
    
    while (j < m && vis[j]) j++;
    if (j == m) return 1;
    checkPath(j);
    return count(vis.begin(), vis.end(), 0) == 0 && depth[lca(p[0], p[j])] <= depth[p.back()];
}

int main()
{
    fast;
    n = II;
    g.resize(n);
    for (int i = 1; i < n; i++) {
        int u = II - 1, v = II - 1;
        g[u].push_back(v);
        g[v].push_back(u);
    }

    lcaPreprocess();
    for (int q = II; q; q--)
        cout << (query() ? "YES" : "NO") << "\n";
    return 0;
}