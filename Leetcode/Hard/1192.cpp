#include "../../headers.h"

// @ Tarjan's Algorithm

#define vv vector<vector<int>>
#define vec vector<int>
#define pb push_back
#define fast ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);

class Solution
{
    vec vis, Time, low, par;
    vv g, ans;
    int timer = 0;
    void TarjansAlgo(int u)
    {
        vis[u] = 1;
        Time[u] = low[u] = timer++;
        for (int v : g[u])
            if (!vis[v])
            {
                par[v] = u;
                TarjansAlgo(v);
                low[u] = min(low[u], low[v]);
                if (low[v] > Time[u])
                    ans.pb({u, v});
            }
            else if (v != par[u])
                low[u] = min(low[u], Time[v]);
    }

public:
    vv criticalConnections(int n, vv &edges)
    {
        vis = vec(n, 0);
        Time = low = par = vec(n, -1);
        g = vv(n);
        for (auto e : edges)
            g[e[0]].pb(e[1]), g[e[1]].pb(e[0]);

        for (int i = 0; i < n; i++)
            if (!vis[i])
                TarjansAlgo(i);
        return ans;
    }
};