#include <bits/stdc++.h>
using namespace std;
 
#define fast ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
#define II ({ int a; cin>>a; a; })

class LCA
{
    int n, maxDepth;
    vector<int> depth;
    vector<vector<int>> ancestor;

    void dfs(vector<int> &g, int u, int par, int d) {
        ancestor[u][0] = par;
        depth[u] = d;
        for (int i = 1; i < maxDepth; i++)
            ancestor[u][i] = ancestor[ancestor[u][i - 1]][i - 1];
        if (g[u] != par)
            dfs(g, g[u], u, d + 1);
    }

public:
    LCA(int n, vector<int> &g) {
        this->n = n;
        maxDepth = log2(n) + 1;
        ancestor.resize(n, vector<int>(maxDepth, -1));
        depth.resize(n, 0);
        dfs(g, 1, 0, 0);
    }

    int lca(int u, int v) {
        int a = u, dist = 0;
        if (depth[u] > depth[v])
                swap(u, v);

        for (int k = 0; (1 << k) <= depth[v] - depth[u]; k++)
            if ((1 << k) & depth[v] - depth[u])
                v = ancestor[v][k];

        for (int k = maxDepth - 1; k >= 0; k--, dist++)
            if (ancestor[u][k] != ancestor[v][k]) {
                u = ancestor[u][k];
                v = ancestor[v][k];
            }
        
        return u == v ? u : ancestor[u][0];
        if (u != a && ancestor[u][0] != a)
            return -1;
        return dist;
    }
};
 
int main()
{
    fast;
    int n = II, q = II;
    vector<int> g(n + 1);
    for (int i = 1; i <= n; i++)
        g[i] = II;
    
    LCA tree(n + 1, g);
    while (q--) {
        int a = II, b = II;
        cout << tree.lca(a, b) << "\n";
    }
    return 0;
}