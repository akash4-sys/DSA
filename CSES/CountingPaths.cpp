#include <bits/stdc++.h>
using namespace std;

#define fast ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
#define II ({ int a; cin >> a; a; })
#define pv(v) {{ for(auto &x : v) cout << x << " "; } cout << endl;}

int n, maxDepth;
vector<int> depth, par;
vector<vector<int>> ancestor, g;

void dfs(vector<vector<int>> &g, int u, int p) {
    ancestor[u][0] = p;
    for (int i = 1; i < maxDepth; i++)
        ancestor[u][i] = ancestor[ancestor[u][i - 1]][i - 1];
    for (int &v : g[u])
        if (v != p) {
            depth[v] = depth[u] + 1;
            par[v] = u;
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

int main()
{
    fast;
    int m;
    cin >> n >> m;
    g.resize(n);
    maxDepth = log2(n) + 1;
    ancestor.resize(n, vector<int>(maxDepth, -1));
    depth.resize(n, 0);
    par.resize(n, -1);
    
    for (int x = n - 1; x; x--)  {
        int u = II - 1, v = II - 1;
        g[u].push_back(v);
        g[v].push_back(u);
    }
    dfs(g, 0, 0);
    
    vector<int> ans(n, 0), deg(n, 0);
    while (m--) {
        int u = II - 1, v = II - 1, root = lca(u, v);
        ans[u]++, ans[v]++, ans[root]--;
        if (par[root] != -1)
            ans[par[root]] -= 1;
    }

    for (int u = 1; u < n; u++)
        deg[par[u]]++;
    
    queue<int> q;
    for (int u = 1; u < n; u++)
        if (!deg[u])
            q.push(u);
    
    while (!q.empty()) {
        int u = q.front();
        q.pop();
        if (par[u] != -1) {
            ans[par[u]] += ans[u];
            if (--deg[par[u]] == 0)
                q.push(par[u]);
        }
    }
    pv(ans);
    return 0;
}