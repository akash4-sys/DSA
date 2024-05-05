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
    int n = II, m = II, k = II;
    vector<int> gov(k), vis(n, 0);
    for (int &gv : gov)
        gv = II - 1;
    
    vector<vector<int>> g(n);
    for (int i = 0; i < m; i++) {
        int u = II - 1, v = II - 1;
        g[u].push_back(v);
        g[v].push_back(u);
    }

    function<int(int)> dfs = [&](int u) -> int {
        vis[u] = 1;
        int res = 1;
        for (int v : g[u])
            if (!vis[v])
                res += dfs(v);
        return res;
    };

    int h = 0, sum = 0, ans = -m;
    for (int i = 0; i < k; i++) {
        gov[i] = dfs(gov[i]);
        sum += gov[i];
        if (gov[h] < gov[i])
            h = i;
    }

    gov[h] += n - sum;
    for (int cnt : gov)
        ans += (cnt * (cnt - 1) / 2);
    cout << ans;
    return 0;
}