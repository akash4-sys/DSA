#include <bits/stdc++.h>
using namespace std;

class LCA
{
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

public:
    LCA(int n, vector<vector<int>> &g) {
        this->n = n;
        maxDepth = log2(n) + 1;
        ancestor.resize(n, vector<int>(maxDepth, -1));
        depth.resize(n, 0);
        dfs(g, 0, 0);
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
};

int main()
{
    int n, q;
    cin >> n >> q;
    vector<vector<int>> g(n);
    for (int i = 1, u; i < n; i++) {
        cin >> u;
        g[u - 1].push_back(i);
    }

    LCA tree(n, g);
    while (q--) {
        int u, v;
        cin >> u >> v;
        cout << tree.lca(u - 1, v - 1) + 1 << "\n";
    }
    return 0;
}