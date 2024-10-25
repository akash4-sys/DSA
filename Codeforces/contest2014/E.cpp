#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define vec vector<ll>
#define vv vector<vec>
#define fast ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
#define II ({ int a; cin>>a; a; })
#define pl(x) cout << x << "\n"
#define p pair<ll, ll>

vv minDistance(vector<vector<p>> &g, vec &horse, int src)
{
    int n = g.size();
    vv dist(n, vec(2, LLONG_MAX));
    priority_queue<vec, vector<vec>, greater<vec>> pq;
    pq.push({0, src, horse[src]});
    dist[src][0] = 0;
    if (horse[src])
        dist[src][1] = 0;

    while (!pq.empty())
    {
        auto v = pq.top();
        ll w = v[0], u = v[1], isHorse = v[2];
        pq.pop();
        for (auto [v, wt] : g[u])
        {
            if (isHorse)
                wt /= 2;
            if (w + wt < dist[v][isHorse]) {
                dist[v][isHorse] = w + wt;
                pq.push({dist[v][isHorse], v, isHorse || horse[v]});
            }
        }
    }
    return dist;
}

ll solve()
{
    int n = II, m = II, h = II;
    vec horse(n + 1, 0);
    for (int i = 0; i < h; i++)
        horse[II]++;
    
    vector<vector<p>> g(n + 1);
    for (int i = 0; i < m; i++) {
        int u = II, v = II, w = II;
        g[u].push_back({v, w});
        g[v].push_back({u, w});
    }

    auto d1 = minDistance(g, horse, 1);
    auto d2 = minDistance(g, horse, n);

    ll ans = LLONG_MAX;
    for (int i = 1; i <= n; i++)
        ans = min(ans, max(min(d1[i][0], d1[i][1]), min(d2[i][0], d2[i][1])));
    return ans == LLONG_MAX ? -1 : ans;
}

int main()
{
    fast;
    for (int tc = II; tc; tc--)
        pl(solve());
    return 0;
}