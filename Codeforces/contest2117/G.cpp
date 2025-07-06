#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define vec vector<ll>
#define vv vector<vec>
#define p pair<ll, ll>
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

vector<ll> maxDist(vector<vector<p>> &g, int src)
{
    int n = g.size();
    priority_queue<p, vector<p>, greater<p>> pq;
    vector<ll> dist(n, LLONG_MAX);

    pq.push({0, src});
    dist[src] = 0;
    while (!pq.empty())
    {
        auto [w, u] = pq.top();
        pq.pop();
        if (w > dist[u])
            continue;
        for (auto [v, wt] : g[u])
            if (max(dist[u], wt) < dist[v]) {
                dist[v] = max(dist[u], wt);
                pq.push({dist[v], v});
            }
    }
    return dist;
}

ll solve()
{
    ll n = LL, m = LL, ans = LLONG_MAX;
    vector<vector<p>> g(n);
    while (m--) {
        ll u = LL - 1, v = LL - 1, w = LL;
        g[u].push_back({v, w});
        g[v].push_back({u, w});
    }

    auto x = maxDist(g, 0), y = maxDist(g, n - 1);
    for (int i = 0; i < n; i++)
        for (auto &[v, w] : g[i])
            ans = min(ans, max({x[i], y[v], w}) + w);
    return ans;
}

int main()
{
    fast;
    for (int tc = II; tc; tc--)
        pl(solve());
    return 0;
}