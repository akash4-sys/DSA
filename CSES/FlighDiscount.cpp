#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define vec vector<ll>

int main()
{
    int n, m;
    cin >> n >> m;
    priority_queue<vec, vector<vec>, greater<vec>> pq;
    vector<vector<pair<int, int>>> g(n + 1);
    vector<vec> dist(n + 1, vec(2, LLONG_MAX));
    while (m--) {
        int u, v, w;
        cin >> u >> v >> w;
        g[u].push_back({v, w});
    }

    pq.push({0, 1, 1});
    dist[1][1] = 0;
    while (!pq.empty())
    {
        ll w = pq.top()[0], u = pq.top()[1], k = pq.top()[2];
        pq.pop();
        if (w > dist[u][k])
            continue;
        for (auto &p : g[u])
        {
            ll v = p.first, wt = p.second;
            if (w + wt < dist[v][k]) {
                dist[v][k] = w + wt;
                pq.push({w + wt, v, k});
            }
            if (k && w + (wt / 2) < dist[v][0]) {
                dist[v][0] = w + (wt / 2);
                pq.push({dist[v][0], v, 0});
            }
        }
    }
    cout << min(dist[n][0], dist[n][1]);
    return 0;
}