#include <bits/stdc++.h>
using namespace std;

// find maximum value cycle and then choose one path from that cycle that leads to outer node
// if there are no cycles then it's a tree and this algo without visited should work

int main()
{
    int n, m;
    cin >> n >> m;
    vector<int> coins(n), vis(n, 0), dp(n, -1);
    for (int &a : coins)
        cin >> a;
    
    vector<vector<int>> g(n);
    for (int i = 0, u, v; i < m; i++) {
        cin >> u >> v;
        g[u - 1].push_back(v - 1);
    }

    auto dfs = [&](auto &&dfs, int u) -> int {
        vis[u] = 1;
        if (dp[u] != -1)
            return dp[u];
        
        int res = 0;
        for (int &v : g[u])
            if (!vis[v])
                res = max(res, dfs(dfs, v) + coins[v]);
        vis[u] = 0;
        return dp[u] = res;
    };

    int ans = 0;
    for (int i = 0; i < n; i++)
        ans = max(ans, dfs(dfs, i) + coins[i]);
    cout << ans;
    return 0;
}