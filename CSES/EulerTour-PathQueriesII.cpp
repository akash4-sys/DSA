#include <bits/stdc++.h>
using namespace std;

#define fast ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
#define II ({ int a; cin >> a; a; })
#define pv(v) {{ for(auto &x : v) cout << x << " "; } cout << endl;}

class LazySegTree {
    int n;
    vector<int> tree, lazy;

public:
    LazySegTree(int n) : n(n), tree(4*n, 0), lazy(4*n, 0) {}

    void push(int i) {
        if (lazy[i] == 0) return;
        for (int ch : {i*2, i*2+1}) {
            tree[ch] += lazy[i];
            lazy[ch] += lazy[i];
        }
        lazy[i] = 0;
    }

    void update(int l, int r, int val, int i=1, int tl=0, int tr=-1) {
        if (tr == -1) tr = n-1;
        if (l > r) return;
        if (l == tl && r == tr) {
            tree[i] += val;
            lazy[i] += val;
            return;
        }
        push(i);
        int mid = (tl + tr) / 2;
        update(l, min(r, mid), val, i*2, tl, mid);
        update(max(l, mid+1), r, val, i*2+1, mid+1, tr);
        tree[i] = max(tree[i*2], tree[i*2+1]);
    }

    int query(int l, int r, int i=1, int tl=0, int tr=-1) {
        if (tr == -1) tr = n-1;
        if (l > r) return INT_MIN;
        if (l == tl && r == tr) return tree[i];
        push(i);
        int mid = (tl + tr) / 2;
        return max(
            query(l, min(r, mid), i*2, tl, mid),
            query(max(l, mid+1), r, i*2+1, mid+1, tr)
        );
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
    vector<int> a(n), start(n), end(n);
    for (int &c : a)
        c = II;
    
    vector<vector<int>> g(n);
    while (m--) {
        int u = II - 1, v = II - 1;
        g[u].push_back(v);
        g[v].push_back(u);
    }

    LazySegTree tree(n + 10);
    LCA o(n, g);
    auto dfs = [&](auto &&dfs, int u, int par) -> void {
        start[u] = ++timer;
        for (int v : g[u])
            if (v != par)
                dfs(dfs, v, u);
        end[u] = timer;
        tree.update(start[u], end[u], a[u]);
    };
    dfs(dfs, 0, -1);
    // pv(start);pv(end);
    
    while (q--)
    {
        int type = II, u = II - 1;
        if (type == 1) {
            int x = II;
            tree.update(start[u], end[u], x);
            a[u] = x;
        }
        else {
            int v = II - 1, root = o.lca(u, v);
            cout << max(tree.query(start[root], start[u]), tree.query(start[root], start[v])) << " ";
        }
    }
    return 0;
}