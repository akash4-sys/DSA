#ifdef __INTELLISENSE__
#include "../../headers.h"
#else
#include <bits/stdc++.h>
using namespace std;
#endif

#define ll long long
#define p pair<ll, ll>
#define vec vector<ll>
#define vv vector<vec>
#define fast ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
#define LL ({ ll a; cin>>a ; a; })
#define pf(x) cout << x << " "
#define pl(x) cout << x << endl
#define br cout << endl
#define pv(v) { for(auto &x : v) pf(x)<<" "; }
#define pvv(mat) { for(auto &r : mat) {pv(r); br;} }

vec shortestDist(vector<vector<p>> &adj, ll n, ll src)
{
    priority_queue<p, vector<p>, greater<p>> pq;
    vec vis(n, 0), dist(n, INT_MAX);
    pq.push({0, src});
    dist[src] = 0;

    while (!pq.empty())
    {
        auto [w, u] = pq.top();
        pq.pop();
        vis[u] = 1;
        for (auto [v, cw] : adj[u])
            if (!vis[v] && w + cw < dist[v])
                dist[v] = w + cw, pq.push({dist[v], v});
    }
    return dist;
}

vv setMaxWeight(vv &edges, ll it)
{
    for (ll i = it + 1; i < edges.size(); i++)
        edges[i][2] = !edges[i][2] ? 1e18 : edges[i][2];
    return edges;
}

vv modifyEdges(ll n, ll m, vv &edges, ll src, ll dest, ll t)
{
    vector<vector<p>> adj(n);
    for (auto e : edges)
        if (e[2])
        {
            adj[e[0]].push_back({e[1], e[2]});
            adj[e[1]].push_back({e[0], e[2]});
        }
    
    auto dist = shortestDist(adj, n, src);
    if (dist[dest] < t)
        return {};
    
    if (dist[dest] == t)
        return setMaxWeight(edges, -1);

    for (ll i = 0; i < m; i++)
    {
        ll u = edges[i][0], v = edges[i][1];
        if (edges[i][2])
            continue;

        edges[i][2] = 1;
        adj[u].push_back({v, 1});
        adj[v].push_back({u, 1});
        dist = shortestDist(adj, n, src);

        if (dist[dest] > t)
            continue;

        edges[i][2] += (t - dist[dest]);
        return setMaxWeight(edges, i);
    }
    return {};
}

int main()
{
    fast;
    ll n = LL, m = LL, t = LL, src = LL, dst = LL;
    vv edges(m);
    for (int i = 0; i < m; i++)
        edges[i] = {LL, LL, LL};
    
    auto ans = modifyEdges(n, m, edges, src, dst, t);
    if (ans.empty())
        pl("NO");
    else
    {
        pl("YES"); 
        pvv(ans);
    }
    return 0;
}