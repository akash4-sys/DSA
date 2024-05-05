#ifdef __INTELLISENSE__
#include "../../headers.h"
#else
#include <bits/stdc++.h>
using namespace std;
#endif

#define ll long long
#define fast ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
#define II ({ int a; cin>>a; a; })
#define p pair<int, int>

ll power(ll a, ll b, ll mod) {
    ll res = 1;
    for (a %= mod; b > 0; b >>= 1)
    {
        if (b & 1)
            res = (res * a) % mod;
        a = (a * a) % mod;
    }
    return res;
}

int main()
{
    fast;
    ll n = II, k = II;
    vector<vector<p>> g(n);
    for (int i = 1; i < n; i++) {
        int u = II - 1, v = II - 1, x = II;
        g[u].push_back({v, x});
        g[v].push_back({u, x});
    }

    vector<int> vis(n, 0);
    function<ll(ll)> dfs = [&](ll u) -> ll {
        vis[u] = 1;
        ll res = 1;
        for (auto [v, x] : g[u])
            if (x == 0 && !vis[v])
                res += dfs(v);
        return res;
    };

    ll mod = 1e9 + 7, ans = power(n, k, mod);
    for (int i = 0; i < n; i++)
        if (!vis[i]) {
            ll cnt = dfs(i);
            ans = (ans - power(cnt, k, mod) + mod) % mod;
        }
    cout << ans;
    return 0;
}