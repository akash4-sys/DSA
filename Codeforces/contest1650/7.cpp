#ifdef __INTELLISENSE__
#include "../../headers.h"
#else
#include <bits/stdc++.h>
using namespace std;
#endif

#define ll long long
#define fast ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
#define II ({ int a; cin>>a; a; })

ll solve()
{
    int n = II, m = II, s = II - 1, t = II - 1, mod = 1e9 + 7;
    vector<vector<int>> g(n);
    for (int i = 0; i < m; i++) {
        int u = II - 1, v = II - 1;
        g[u].push_back(v);
        g[v].push_back(u);
    }

    auto bfs = [&](int src) {
        vector<ll> dist(n, -1), cnt(n, 0);
        queue<int> q;
        q.push(src);
        dist[src] = 0;
        cnt[src] = 1;

        while (!q.empty())
        {
            int u = q.front();
            q.pop();
            for (int &v : g[u]) {
                if (dist[v] == -1)
                    dist[v] = dist[u] + 1, q.push(v);
                if (dist[v] == dist[u] + 1)
                    (cnt[v] += cnt[u]) %= mod;
            }
        }
        return pair(dist, cnt);
    };

    auto [ds, cs] = bfs(s);
    auto [dt, ct] = bfs(t);
    ll ans = cs[t];
    for (int u = 0; u < n; u++)
        for (int v : g[u])
            if (ds[u] + dt[v] == ds[t] && ds[u] == ds[v])
                (ans += ((cs[u] * ct[v]) % mod)) %= mod;
    return ans;
}

int main()
{
    fast;
    int tc = II;
    while (tc--)
        cout << solve() << "\n";
    return 0;
}