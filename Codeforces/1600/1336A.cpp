#include <bits/stdc++.h>
using namespace std;

#define fast ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
#define II ({ int a; cin >> a; a; })

int main()
{
    int n = II, m = n - 1, k = II;
    vector<vector<int>> g(n);
    while (m--) {
        int u = II - 1, v = II - 1;
        g[u].push_back(v);
        g[v].push_back(u);
    }

    vector<int> par(n, -1), h(n, 0), cnt(n, 0);
    priority_queue<pair<int, int>> pq;
    auto dfs = [&](auto &&dfs, int u) -> void {
        if (g[u].size() == 1 && par[u] != -1)
            pq.push({h[u], u});
        for (int v : g[u])
            if (par[u] != v) {
                par[v] = u;
                h[v] = h[u] + 1;
                dfs(dfs, v);
            }
    };
    dfs(dfs, 0);

    long long ans = 0;
    while (k)
    {
        int happ = pq.top().first, u = pq.top().second;
        pq.pop();
        if (h[u] != happ)
            continue;

        k--;
        ans += h[u];
        if (par[u] != -1) {
            cnt[par[u]] += ++cnt[u];
            h[par[u]] -= cnt[u];
            pq.push({h[par[u]], par[u]});
        }
    }
    cout << ans;
    return 0;
}