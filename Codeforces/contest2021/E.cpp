#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define vec vector<ll>
#define vv vector<vec>
#define all(v) v.begin(), v.end()
#define fast ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
#define II ({ int a; cin>>a; a; })
#define pv(v) {{ for(auto &x : v) cout << x << " "; } cout << "\n";}
#define pvv(a) ({ for(auto &v : a) pv(v); })

void solve()
{
    ll n = II, m = II, p = II;
    vector<ll> h(p);
    for (auto &x : h)
        cin >> x;

    vector g(n + 1, vector<ll>(n + 1, INT_MAX));
    for (int i = 0; i < m; i++) {
        int u = II, v = II, w = II;
        g[u][v] = g[v][u] = w;
    }

    vector<vector<ll>> dist = g;
    for (int k = 0; k <= n; k++)
        dist[k][k] = 0;

    for (int k = 0; k <= n; k++)
        for (int i = 0; i <= n; i++)
            for (int j = 0; j <= n; j++)
                dist[i][j] = min(dist[i][j], dist[i][k] + dist[k][j]);
    
    vector<ll> curr(n + 1, INT_MAX), prov(n + 1, INT_MAX);
    for (int k = 1; k <= n; k++)
    {
        ll best = LLONG_MAX, idx = -1;
        for (int i = 1; i <= n; i++)
            if (prov[i]) {
                ll wifi = 0;
                for (auto &x : h)
                    wifi += min(curr[x], dist[x][i]);
                if (wifi <= best) {
                    best = wifi;
                    idx = i;
                }
            }
        for (auto &x : h)
            curr[x] = min(curr[x], dist[x][idx]);
        prov[idx] = 1;
        cout << best << " ";
    }
    cout << "\n";
}

int main()
{
    fast;
    for (int tc = II; tc; tc--)
        solve();
    return 0;
}