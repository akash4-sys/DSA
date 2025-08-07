#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define vec vector<int>
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

ll solve()
{
    int n = II, m = n - 1, q = II;
    vec col(n), par(n, -1); 
    iv(col);
    vector<vector<pair<int, int>>> g(n);
    while (m--) {
        int u = II - 1, v = II - 1;
        g[u].emplace_back(v, w);
        g[v].emplace_back(u, w);
    }
    
    vector<ll> weight(n, 0), sum(n, 0);
    vector<map<int, ll>> child(n);
    [&](this auto &&self, int u) -> void {
        for (auto &[v, w]: g[u])
            if (v != par[u]) {
                par[v] = u;
                weight[v] += w;
                self(v);
            }
    }(0);

    ll ans = 0;
    for (int u = 1; u < n; u++) {
        if (col[u] != col[par[u]])
            ans += weight[u];
        sum[par[u]] += weight[u];
        child[par[u]][col[u]] += weight[u];
    }

    while (q--) {
        int u = II - 1, v = II - 1;
    }
}

int main()
{
    fast;
    for (int tc = II; tc;   tc--)
        pl(solve());
    return 0;
}