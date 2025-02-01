#include <bits/stdc++.h>
using namespace std;

#define fast ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
#define II ({ int a; cin >> a; a; })

vector<int> depth, treeSize, val;

int dfs(vector<vector<int>> &g, int u, int p)
{
    depth[u] = depth[p] + 1;
    treeSize[u] = 1;
    for (int v : g[u])
        if (v != p)
            treeSize[u] += dfs(g, v, u);
    val[u] = treeSize[u] - depth[u];
    return treeSize[u];
}

int main()
{
    int n = II, k = II, m = n - k + 1;
    vector<vector<int>> g(n + 1);
    for (int i = 1; i < n; i++) {
        int u = II, v = II;
        g[u].push_back(v);
        g[v].push_back(u);
    }

    treeSize = depth = val = vector<int>(n + 1, 0);
    dfs(g, 1, 0);
    nth_element(val.begin() + 1, val.begin() + m, val.end(), [&](int &a, int &b){
        return a > b;
    });
    cout << accumulate(val.begin(), val.begin() + m, 0LL);
    return 0;
}