#include <bits/stdc++.h>
using namespace std;

#define fast ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
#define ll long long
#define II ({ int a; cin >> a ; a; })
#define M 998244353
#define pv(v) {{ for(auto &x : v) cout << x << " "; } cout << endl;}

class LazySegmentTree
{
    ll n;
    vector<ll> tree, lazy;
public:
    LazySegmentTree(int N): n(N), tree(N * 4, 0), lazy(N * 4, 0) {}

    ll query(int l, int r, int i = 1, int tl = 0, int tr = -1)
    {
        if (tr == -1) 
            tr = n - 1;
        if (l > r)
            return 0;
        if (l == tl && r == tr)
            return tree[i] + ((tr - tl + 1LL) * lazy[i]);

        int mid = (tl + tr) / 2;
        ll queryLeft = query(l, min(r, mid), i * 2, tl, mid);
        ll queryRight = query(max(l, mid + 1), r, i * 2 + 1, mid + 1, tr);
        return (r - l + 1LL) * lazy[i] + queryLeft + queryRight;
    }

    void update(int l, int r, int val = 1, int i = 1, int tl = 0, int tr = -1)
    {
        if (tr == -1) 
            tr = n - 1;
        if (l == tl && r == tr)
            lazy[i] += val;
        else if (l <= r)
        {
            lazy[i * 2] += lazy[i];
            lazy[i * 2 + 1] += lazy[i];
            lazy[i] = 0;
            int mid = (tl + tr) / 2;
            update(l, min(r, mid), val, i * 2, tl, mid);
            update(max(l, mid + 1), r, val, i * 2 + 1, mid + 1, tr);
            tree[i] = query(tl, mid, i * 2, tl, mid) + query(mid + 1, tr, i * 2 + 1, mid + 1, tr);
        }
    }
};

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
    int n = II, q = II, m = n - 1, timer = 0;
    vector<vector<int>> g(n);
    while (m--) {
        int u = II - 1, v = II - 1;
        g[u].push_back(v);
        g[v].push_back(u);
    }

    vector<int> treeSize(n, 0), idx(n);
    auto dfs = [&](auto &&dfs, int u, int par) -> void {
        treeSize[u]++;
        for (int v : g[u])
            if (v != par) {
                dfs(dfs, v, u);
                treeSize[u] += treeSize[v];
            }
        idx[u] = timer++;
    };
    dfs(dfs, 0, -1);

    LazySegmentTree tree(n);
    LCA lcaTree(n, g);
    while (q--)
    {
        int type = II, u = II - 1;
        if (type == 2) {
            cout << tree.query(idx[u], idx[u]) << "\n";
            continue;
        }
        
        int val = II;
        for (int r = 0; r < 3; r++)
            if (r == u)
                tree.update(0, n - 1, val);
            else
            {
                if (lcaTree.lca(u, r) == u) {
                    tree.update(0, n - 1, val);
                    tree.update(idx[r] - treeSize[r] + 1, idx[r], -val);
                }
                else
                    tree.update(0, idx[u], val);
            }
    }
    return 0;
}