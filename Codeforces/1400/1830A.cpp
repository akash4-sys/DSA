#ifdef __INTELLISENSE__
#include "../../headers.h"
#else
#include <bits/stdc++.h>
using namespace std;
#endif

#define fast ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
#define II ({ int a; cin>>a; a; })
#define pl(x) cout << x << endl

int solve()
{
    int n = II;
    vector<int> dp(n + 1, 0), id(n + 1, 0);
    vector<vector<pair<int, int>>> g(n + 1);
    for (int i = 1; i < n; i++)
    {
        int u = II, v = II;
        g[u].push_back({v, i});
        g[v].push_back({u, i});
    }

    dp[1] = 1;
    function<void(int)> dfs = [&](int u){
        for (auto [v, idx] : g[u])
            if (!dp[v]) {
                dp[v] = dp[u] + (idx <= id[u]);
                id[v] = idx;
                dfs(v);
            }
    };
    dfs(1);
    return *max_element(dp.begin(), dp.end());
}

int main()
{
    fast;
    int tc = II;
    while (tc--)
        pl(solve());
    return 0;
}