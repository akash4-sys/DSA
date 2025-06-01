#include <bits/stdc++.h>
using namespace std;

#define fast ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
#define II ({ int a; cin>>a; a; })

int main()
{
    fast;
    int n = II, m = II;
    vector<vector<int>> g(n + 1);
    for (int i = 0; i < m; i++) {
        int u = II, v = II;
        g[u].push_back(v);
        g[v].push_back(u);
    }

    vector<int> city, vis(n + 1, 0);
    auto dfs = [&](auto &&dfs, int u) -> void {
        vis[u] = 1;
        for (int &v : g[u])
            if (!vis[v])
                dfs(dfs, v);
    };

    for (int u = 1; u <= n; u++)
        if (!vis[u]) {
            dfs(dfs, u);
            city.push_back(u);
        }
    
    cout << city.size() - 1 << "\n";
    for (int i = 1; i < city.size(); i++)
        cout << 1 << " " << city[i] << "\n";
    return 0;
}