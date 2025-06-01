#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define vec vector<ll>
#define fast ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
 
int main()
{
    fast;
    int n, m, k;
    cin >> n >> m >> k;
    priority_queue<vec, vector<vec>, greater<vec>> pq;
    vector<vector<vec>> g(n + 1);
    vec vis(n + 1, 0);
    while (m--) {
        int u, v, w;
        cin >> u >> v >> w;
        g[u].push_back({v, w});
    }
 
    pq.push({0, 1});
    while (!pq.empty())
    {
        ll w = pq.top()[0], u = pq.top()[1];
        pq.pop();
        if (vis[u] >= k)
            continue;
        if (u == n)
            cout << w << " ";
        vis[u]++;
        for (auto &p : g[u])
            pq.push({w + p[1], p[0]});
    }
    return 0;
}