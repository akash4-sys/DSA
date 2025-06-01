#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define LL ({ ll a; cin>>a ; a; })

class DSU
{
    vector<int> parent;
public:
    DSU(int n) : parent(n) {
        iota(parent.begin(), parent.end(), 0);
    }

    int findParent(int u) {
        return parent[u] == u ? u : parent[u] = findParent(parent[u]);
    }

    bool Union(int u, int v)
    {
        int uPar = findParent(u), vPar = findParent(v);
        if (uPar == vPar)
            return 1;
        parent[uPar] = vPar;
        return 0;
    }
};

int main()
{
    ll n = LL, m = LL, cost = 0, edges = 0;
    priority_queue<vector<ll>> pq;
    while (m--) {
        ll u = LL - 1, v = LL - 1, w = LL;
        pq.push({-w, u, v});
    }
    DSU dsu(n);

    while (!pq.empty() && edges < n - 1)
    {
        auto t = pq.top();
        pq.pop();
        ll w = -t[0], u = t[1], v = t[2];
        if (!dsu.Union(u, v))
            cost += w, edges++;
    }

    if (edges == n - 1) {
        cout << cost;
        return 0;
    }
    cout << "IMPOSSIBLE";
    return 0;
}