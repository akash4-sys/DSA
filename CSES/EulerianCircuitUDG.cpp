#include <bits/stdc++.h>
using namespace std;

#define p pair<int, int>
#define II ({ int a; cin>>a ; a; })
#define fast ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);

int n, m;
vector<vector<p>> g;
vector<int> vis, path;

void dfs(int u)
{
    while (g[u].size()) {
        auto &[v, i] = g[u].back();
        g[u].pop_back();
        if (!vis[i])
            vis[i] = 1, dfs(v);
    }
    path.push_back(u);
}

int main()
{
    fast;
    n = II, m = II;
    g.resize(n);
    vis.resize(m + 1, 0);
    for (int i = 0; i < m; i++) {
        int u = II - 1, v = II - 1;
        g[u].push_back({v, i});
        g[v].push_back({u, i});
    }

    for (int i = 0; i < n; i++)
        if (g[i].size() % 2) {
            cout << "IMPOSSIBLE";
            return 0;
        }
    
    dfs(0);
    if (path.size() != m + 1) {
        cout << "IMPOSSIBLE";
        return 0;
    }
    for (int &x : path)
        cout << x + 1 << " ";
    return 0;
}