#include <bits/stdc++.h>
using namespace std;
#define fast ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
#define II ({ int a; cin >> a; a; })

int n, maxDepth;
vector<int> depth;
vector<vector<int>> ancestor;

void dfs(vector<vector<int>> &g, int u, int par) {
    ancestor[u][0] = par;
    for (int i = 1; i < maxDepth; i++)
        ancestor[u][i] = ancestor[ancestor[u][i - 1]][i - 1];
    for (int &v : g[u])
        if (v != par) {
            depth[v] = depth[u] + 1;
            dfs(g, v, u);
        }
}

int lca(int u, int v) {
    if (depth[u] > depth[v])
        swap(u, v);
    
    int k = depth[v] - depth[u];
    for (int i = 0; (1 << i) <= k; i++)
        if (k & (1 << i))
            v = ancestor[v][i];

    for (int i = maxDepth - 1; i >= 0; i--)
        if (ancestor[u][i] != ancestor[v][i])
            u = ancestor[u][i], v = ancestor[v][i];
    return u == v ? u : ancestor[u][0];
}

int dist() {
    int u = II - 1, v = II - 1;
    if (u == 0 || v == 0)
        return depth[u ? u : v];
    return depth[u] + depth[v] - (depth[lca(u, v)] * 2);
}

int main()
{
    fast;
    int q;
    cin >> n >> q;
    vector<vector<int>> g(n);
    for (int m = n - 1; m; m--)  {
        int u = II - 1, v = II - 1;
        g[u].push_back(v);
        g[v].push_back(u);
    }

    maxDepth = log2(n) + 1;
    ancestor.resize(n, vector<int>(maxDepth, -1));
    depth.resize(n, 0);
    dfs(g, 0, 0);

    while (q--)
        cout << dist() << "\n";
    return 0;
}