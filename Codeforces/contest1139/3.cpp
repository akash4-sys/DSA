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

ll power(ll a, ll b, ll mod = 1e9 + 7)
{
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
    ll n = II, k = II, remove = n, mod = 1e9 + 7;
    vector<vector<p>> g(n);
    for (int i = 1; i < n; i++) {
        int u = II - 1, v = II - 1, x = II;
        g[u].push_back({v, x});
        g[v].push_back({u, x});
    }

    vector<int> vis(n, 0);
    function<int(int)> dfs = [&](int u) -> int {
        vis[u] = 1;
        int res = 0;
        for (auto &[v, x] : g[u])
            if (!vis[v] && !x)
                res += dfs(v) + 1;
        return res;
    };

    for (int i = 0; i < n; i++) {
        ll edges = dfs(i);
        (remove += (edges ? (power(edges + 1, k) - edges - 1 + mod) % mod : 0)) %= mod;
    }
    cout << ((power(n, k) - remove) % mod + mod) % mod;
    return 0;
}