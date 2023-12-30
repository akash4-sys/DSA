#ifdef __INTELLISENSE__
#include "../../headers.h"
#else
#include <bits/stdc++.h>
using namespace std;
#endif

#define ll long long
#define p pair<ll, ll>
#define vp vector<vector<p>>
#define vec vector<ll>
#define vv vector<vec>
#define all(v) v.begin(), v.end()
#define fast ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
#define LL ({ ll a; cin>>a ; a; })
#define pl(x) cout << x << endl
#define iv(v) { for(auto &x : v) cin >> x; }

ll minDist(vp &adj, int n, int src, vec &s)
{
    priority_queue<vec, vector<vec>, greater<vec>> pq;
    vv vis(n + 1, vec(1001, 0)), dist(n + 1, vec(1001, LLONG_MAX));

    pq.push({0, s[src], src});
    dist[src][s[src]] = 0;
    while (!pq.empty())
    {
        auto a = pq.top();
        ll u = a[2], k = a[1], w = a[0];
        pq.pop();
        vis[u][k] = 1;
        for (auto [v, wt] : adj[u])
        {
            ll c = min(k, s[v]);
            if (!vis[v][c] && w + (wt * k) < dist[v][c])
            {
                dist[v][c] = w + (wt * k);
                pq.push({dist[v][c], c, v});
            }
        }
    }

    ll res = LLONG_MAX;
    for (int i = 1; i <= 1000; i++)
        res = min(res, dist[n][i]);
    return res;
}

ll solve()
{
    ll n = LL, m = LL;
    vp g(n + 1);
    for (int i = 0; i < m; i++)
    {
        ll u = LL, v = LL, w = LL;
        g[u].push_back({v, w});
        g[v].push_back({u, w});
    }

    vec s(n + 1);
    for (int i = 1; i <= n; i++)
        cin >> s[i];
    return minDist(g, n, 1, s);
}

int main()
{
    fast;
    int tc = LL;
    while (tc--)
        pl(solve());
    return 0;
}