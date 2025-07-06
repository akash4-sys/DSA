
#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define vec vector<ll>
#define vv vector<vec>
#define all(v) v.begin(), v.end()
#define fast ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
#define II ({ int a; cin>>a; a; })
#define LL ({ ll a; cin>>a ; a; })
#define SS ({ string s; cin>>s; s; })
#define pf(x) cout << x << " "
#define pl(x) cout << x << "\n"
#define br cout << "\n"
#define pyn(x) cout << (x ? "YES" : "NO") << "\n"
#define pv(v) {{ for(auto &x : v) pf(x); } br;}
#define pvv(mat) { for(auto &r : mat) pv(r); }
#define iv(v) { for(auto &x : v) cin >> x; }

ll mod = 1e9 + 7;
long long power(long long a, long long b, long long mod)
{
    long long res = 1;
    for (a %= mod; b > 0; b >>= 1)
    {
        if (b & 1)
            res = (res * a) % mod;
        a = (a * a) % mod;
    }
    return res % mod;
}

ll solve()
{
    int n = II, m = n - 1, lca = -1;
    vector<vector<int>> g(n + 1);
    while (m--) {
        ll u = LL, v = LL;
        g[u].push_back(v);
        g[v].push_back(u);
    }

    vec a;
    auto dfs = [&](auto &&dfs, int u, int par, int len) -> void{
        if (g[u].size() > 2)
            lca = len;
        if (g[u].size() == 1)
            a.push_back(len);
        for (int &v : g[u])
            if (v != par)
                dfs(dfs, v, u, len + 1);
    };

    g[1].push_back(0);
    dfs(dfs, 1, 0, 1);
    if (a.size() > 2)
        return 0;
    if (a.size() == 1)
        return power(2, a[0], mod);
    if (a[0] == a[1])
        return power(2, lca + 1, mod);
    return ((power(2, abs(a[0] - a[1]) - 1, mod) * 3LL % mod) * power(2, lca, mod)) % mod;
}

int main()
{
    fast;
    for (int tc = II; tc; tc--)
        pl(solve());
    return 0;
}