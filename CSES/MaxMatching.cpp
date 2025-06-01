#include <bits/stdc++.h>
using namespace std;

int main()
{
    int n, m, k, u, v, pairs = 0;
    cin >> n >> m >> k;
    vector<vector<int>> g(n + 1);
    while (k--) {
        cin >> u >> v;
        g[u].push_back(v);
    }
    
    vector<int> p(m + 1, 0), vis(m + 1, 0);
    auto dfs = [&](auto &&dfs, int u) -> bool {
        for (int &v : g[u])
            if (!vis[v]) {
                vis[v] = 1;
                if (!p[v] || dfs(dfs, p[v])) {
                    p[v] = u;
                    return 1;
                }
            }
            return 0;
    };

    for (int u = 1; u <= n; u++) {
        pairs += dfs(dfs, u);
        vis = vector<int>(m + 1, 0);
    }
    
    cout << pairs << "\n";
    for (int u = 1; u <= m; u++)
        if (p[u])
            cout << p[u] << " " << u << "\n";
    return 0;
}