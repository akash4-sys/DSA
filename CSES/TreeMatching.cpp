#include <bits/stdc++.h>
using namespace std;
#define II ({ int a; cin>>a ; a; })

int main()
{
    int n = II, m = n - 1;
    vector<vector<int>> g(n);
    while (m--) {
        int u = II - 1, v = II - 1;
        g[u].push_back(v);
        g[v].push_back(u);
    }

    vector<int> vis(n, 0);
    auto dfs = [&](auto &&dfs, int u, int par) -> int {
        int res = 0;
        for (int &v : g[u])
            if (v != par && g[v].size())
                res += dfs(dfs, v, u);

        if (!vis[u])
            for (int &v : g[u])
                if (!vis[v]) {
                    vis[u] = vis[v] = 1;
                    return res + 1;
                }
        return res;
    };
    cout << dfs(dfs, 0, -1);
    return 0;
}