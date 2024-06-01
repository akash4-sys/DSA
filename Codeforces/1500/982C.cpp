#ifdef __INTELLISENSE__
#include "../../headers.h"
#else
#include <bits/stdc++.h>
using namespace std;
#endif

#define fast ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
#define II ({ int a; cin>>a; a; })

int main()
{
    fast;
    int n = II, ans = 0;
    vector<vector<int>> g(n);
    for (int i = 1; i < n; i++) {
        int u = II - 1, v = II - 1;
        g[u].push_back(v);
        g[v].push_back(u);
    }

    if (n % 2) {
        cout << -1;
        return 0;
    }

    vector<int> vis(n, 0);
    function<int(int)> dfs = [&](int u) -> int {
        if (g[u].size() == 1 && vis[g[u][0]])
            return 1;
        
        vis[u] = 1;
        int res = 1;
        for (int v : g[u])
            if (!vis[v])
                res += dfs(v);
        
        if (res % 2 == 0)
            ans++, res = 0;
        return res;
    };

    dfs(0);
    cout << ans - 1;
    return 0;
}