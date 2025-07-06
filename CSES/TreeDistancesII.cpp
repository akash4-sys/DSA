#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define II ({ int a; cin>>a ; a; })

int main()
{
    ll n = II, m = n - 1;
    vector<vector<int>> g(n);
    while (m--) {
        int u = II - 1, v = II - 1;
        g[u].push_back(v);
        g[v].push_back(u);
    }

    vector<ll> cnt(n, 0), ans(n, 0);
    auto dfs = [&](auto &&dfs, int u, int par, int d) -> void {
        ans[0] += d;
        cnt[u] = 1;
        for (int &v : g[u])
            if (v != par) {
                dfs(dfs, v, u, d + 1);
                cnt[u] += cnt[v];
            }
    };
    dfs(dfs, 0, -1, 0);
    
    auto dfs1 = [&](auto &&dfs1, int u, int par, int d) -> void {
        for (int &v : g[u])
            if (v != par) {
                ans[v] = ans[u] + n - (cnt[v] * 2);
                dfs1(dfs1, v, u, d + 1);
            }
    };
    dfs1(dfs1, 0, -1, 0);
    for (ll &a : ans)
        cout << a << " ";
    return 0;
}