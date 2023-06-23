#ifdef __INTELLISENSE__
#include "../headers.h"
#else
#include <bits/stdc++.h>
using namespace std;
#endif

#define ll long long
#define vec vector<ll>
#define vv vector<vec>
#define vvv vector<vv>
#define all(v) v.begin(), v.end()
#define fast ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
#define II ({ int a; cin>>a; a; })
#define LL ({ ll a; cin>>a ; a; })
#define SS ({ string s; cin>>s; s; })
#define pf(x) cout << x << " "
#define pl(x) cout << x << endl
#define br cout << endl
#define pv(v) { for(auto &x : v) pf(x)<<" "; }
#define pvv(mat) { for(auto &r : mat) {pv(r); br;} }
#define iv(v) { for(auto &x : v) cin >> x; }
#define p pair<int, int>

void dfs(vv &g, vec &val, int u, int par)
{
    if (g[u].size() == 1 && g[u][0] == par)
        val[u] = 1;
    else
    {
        for (int v : g[u])
        {
            if (v != par)
            {
                dfs(g, val, v, u);
                val[u] += val[v];
            }
        }
    }
}

void solve()
{
    int n = II;
    vv g(n + 1);
    vec val(n + 1, 0);

    for (int i = 0; i < n - 1; i++) {
        ll u = LL, v = LL;
        g[u].push_back(v);
        g[v].push_back(u);
    }

    dfs(g, val, 1, -1);

    int qs = II;
    for (int i = 0; i < qs; i++)
    {
        ll x = LL, y = LL;
        ll ans = 1LL * val[x] * val[y];
        cout << ans << endl;
    }
}

int main()
{
    fast;
    int tc = II;
    while (tc--)
        solve();
    return 0;
}