#include <bits/stdc++.h>
using namespace std;
#define fast ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
#define II ({ int a; cin >> a; a; })
 
vector<int> a;
vector<vector<int>> g;
 
class HLD
{
    int n, pos = 0;
    vector<int> depth, idx, heavy, head, segTree, par;
 
    void segBuild() {
        for (int i = n - 1; i > 0; i--)
            segTree[i] = max(segTree[2 * i], segTree[2 * i + 1]);
    }
 
    int segQuery(int l, int r) {
        int ans = 0;
        for (l += n, r += n + 1; l < r; l >>= 1, r >>= 1) {
            if (l & 1)
                ans = max(ans, segTree[l++]);
            if (r & 1)
                ans = max(ans, segTree[--r]);
        }
        return ans;
    }
 
    int dfs(int u, int p) 
    {
        par[u] = p;
        int treeSize = 1, mxSubSize = 0;
        for (int &v : g[u])
            if (v != p)
            {
                depth[v] = depth[u] + 1;
                int subSize = dfs(v, u);
                treeSize += subSize;
                if (subSize > mxSubSize)
                    mxSubSize = subSize, heavy[u] = v;
            }
        return treeSize;
    }
 
    void decompose(int u, int h)
    {
        head[u] = h;
        segTree[pos + n] = a[u];
        idx[u] = pos++;
        if (heavy[u] != -1)
            decompose(heavy[u], h);
 
        for (int v : g[u])
            if (v != par[u] && v != heavy[u])
                decompose(v, v);
    }
 
public:
    HLD(int N) {
        n = N;
        segTree.resize(n * 2 + 1, 0);
        idx.resize(n);
        depth.resize(n, 0);
        heavy.resize(n, -1);
        head.resize(n);
        par.resize(n, 0);
        dfs(0, 0);
        decompose(0, 0);
        segBuild();
    }
 
    void segUpdate(int u, int val) {
        int i = idx[u] + n;
        segTree[i] = val;
        while (i > 1) {
            i >>= 1;
            segTree[i] = max(segTree[2 * i], segTree[2 * i + 1]);
        }
    }
 
    int query(int u, int v) {
        int res = 0;
        for (; head[u] != head[v]; v = par[head[v]]) {
            if (depth[head[u]] > depth[head[v]])
                swap(u, v);
            res = max(res, segQuery(idx[head[v]], idx[v]));
        }
        
        if (depth[u] > depth[v])
            swap(u, v);
        return max(res, segQuery(idx[u], idx[v]));
    }
};
 
int main()
{
    int n = II, q = II;
    for (int i = 0; i < n; i++)
        a.push_back(II);
 
    g.resize(n);
    for (int m = n - 1; m; m--)  {
        int u = II - 1, v = II - 1;
        g[u].push_back(v);
        g[v].push_back(u);
    }
 
    HLD hld(n);
    while (q--) {
        int type = II, u = II - 1;
        if (type == 1)
            hld.segUpdate(u, II);
        else
            cout << hld.query(u, II - 1) << " ";
    }
    return 0;
}