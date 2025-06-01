#include <bits/stdc++.h>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int n, m;
    cin >> n >> m;
    vector<vector<int>> g(n + 1);
    vector<int> vis(n + 1, 0), ans;
    for (int i = 0; i < m; ++i) {
        int u, v;
        cin >> u >> v;
        g[u].push_back(v);
    }

    auto dfs = [&](auto &&dfs, int u) -> bool {
        if (vis[u])
            return vis[u] == 1;
        vis[u] = 1;
        for (int v : g[u])
            if (dfs(dfs, v)) {
                ans.push_back(v);
                return 1;
            }
        vis[u] = 2;
        return 0;
    };

    bool cycle = false;
    for (int i = 1; i <= n && !cycle; ++i)
        cycle = dfs(dfs, i);

    if (!cycle) {
        cout << "IMPOSSIBLE\n";
        return 0;
    }

    int start = ans[0], i = 1;
    while (i < ans.size() && ans[i] != start) i++;
    cout << i + 1 << "\n";
    for (int j = i - 1; j >= 0; j--)
        cout << ans[j] << " ";
    cout << ans[i - 1] << "\n";
    return 0;
}
