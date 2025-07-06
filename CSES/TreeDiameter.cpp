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

    auto dfs = [&](auto &&dfs, int u, int par, int d, int &a, int &maxDepth) -> void {
        if (d > maxDepth)
            maxDepth = d, a = u;
        for (int &v : g[u])
            if (v != par)
                dfs(dfs, v, u, d + 1, a, maxDepth);
    };

    int a = -1, da = 0, b = -1, db = 0;
    dfs(dfs, 0, -1, 0, a, da);
    dfs(dfs, a, -1, 0, b, db);
    cout << db;
    return 0;
}