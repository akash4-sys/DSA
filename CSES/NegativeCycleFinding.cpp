#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define LL ({ ll a; cin>>a ; a; })

// Faster Bellman ford algorithm

int main()
{
    ll n = LL, m = LL;
    vector<vector<pair<ll, ll>>> g(n);
    while (m--) {
        ll u = LL - 1, v = LL - 1, w = LL;
        g[u].push_back({v, w});
    }

    vector<ll> dist(n, 0);
    vector<int> cnt(n, 0), inQ(n, 1), par(n, -1);
    queue<int> q;
    for (int u = 0; u < n; u++)
        q.push(u);

    auto negativeCycleExists = [&](){
        while (!q.empty()) {
            int u = q.front();
            q.pop();
            inQ[u] = 0;
            for (auto &[v, w] : g[u])
                if (dist[u] + w < dist[v]) {
                    dist[v] = dist[u] + w;
                    par[v] = u;
                    if (!inQ[v]) {
                        inQ[v] = 1;
                        q.push(v);
                        if (++cnt[v] > n)
                            return int(v);
                    }
                }
        }
        return -1;
    };

    int res = negativeCycleExists(), st = res;
    if (res == -1) {
        cout << "NO";
        return 0;
    }

    cout << "YES\n";
    for (int i = 0; i < n; i++)
        st = par[st];
    
    vector<int> cycle = {st};
    for (int u = par[st]; u != st; u = par[u])
        cycle.push_back(u);
    cycle.push_back(st);

    for (int i = cycle.size() - 1; i >= 0; i--)
        cout << cycle[i] + 1 << " ";
    return 0;
}