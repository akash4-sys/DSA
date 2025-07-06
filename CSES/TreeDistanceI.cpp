#include <bits/stdc++.h>
using namespace std;
#define II ({ int a; cin>>a ; a; })

int main()
{
    int n = II, m = n - 1;
    vector<vector<int>> g(n), depth(2, vector<int>(n, 0));
    while (m--) {
        int u = II - 1, v = II - 1;
        g[u].push_back(v);
        g[v].push_back(u);
    }

    auto dfs = [&](auto &&dfs, int u, int par, int i) -> int {
        int x = -1;
        for (int &v : g[u])
            if (v != par) {
                depth[i][v] = depth[i][u] + 1;
                int c = dfs(dfs, v, u, i);
                if (x == -1 || depth[i][c] > depth[i][x])
                    x = c;
            }
        return x == -1 ? u : x;
    };

    int a = dfs(dfs, 0, -1, 0);
    depth[0][a] = 0;
    int b = dfs(dfs, a, -1, 0);
    dfs(dfs, b, -1, 1);
    for (int i = 0; i < n; i++)
        cout << max(depth[0][i], depth[1][i]) << " ";
    return 0;
}