#include <bits/stdc++.h>
using namespace std;

#define vec vector<int>
#define vv vector<vec>
#define all(v) v.begin(), v.end()
#define fast ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
#define II ({ int a; cin>>a; a; })
#define pf(x) cout << x << " "
#define pl(x) cout << x << "\n"
#define br cout << "\n"
#define pv(v) {{ for(auto &x : v) pf(x); } br;}
#define iv(v) { for(auto &x : v) cin >> x; }
#define p pair<int, int>

vec minDistance(vector<vector<int>> &adj, int n, int src = 0)
{
    priority_queue<p, vector<p>, greater<p>> pq;
    vector<int> vis(n, 0), dist(n, INT_MAX);
    pq.push({0, src});
    dist[src] = 0;
    while (!pq.empty())
    {
        int w = pq.top().first, u = pq.top().second;
        pq.pop();
        vis[u] = 1;
        for (int v : adj[u])
            if (!vis[v] && dist[u] + 1 < dist[v])
                dist[v] = dist[u] + 1, pq.push({dist[v], v});
    }
    return dist;
}

void dfs(vv &g, vec &dist, vec &dp, vec &vis, int u)
{
    vis[u] = 1;
    for (int &v : g[u])
    {
        if (!vis[v] && dist[u] < dist[v])
            dfs(g, dist, dp, vis, v);
        if (dist[u] < dist[v])
            dp[u] = min(dp[u], dp[v]);
        else
            dp[u] = min(dp[u], dist[v]);
    }
}

vector<int> solve()
{
    int n = II, m = II;
    vector<vector<int>> g(n);
    for (int i = 0; i < m; i++) {
        int u = II - 1, v = II - 1;
        g[u].push_back(v);
    }

    vector<int> dist = minDistance(g, n), dp = dist, vis(n, 0);
    dfs(g, dist, dp, vis, 0);
    return dp;
}

int main()
{
    fast;
    for (int tc = II; tc; tc--)
        pv(solve());
    return 0;
}