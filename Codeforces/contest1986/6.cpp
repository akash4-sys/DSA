#ifdef __INTELLISENSE__
#include "../../headers.h"
#else
#include <bits/stdc++.h>
using namespace std;
#endif

#define ll long long
#define vec vector<ll>
#define vv vector<vec>
#define vvv vector<vv>
#define all(v) v.begin(), v.end()
#define fast ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
#define II ({ int a; cin>>a; a; })
#define LL ({ ll a; cin>>a ; a; })
#define pf(x) cout << x << " "
#define pl(x) cout << x << endl
#define br cout << endl
#define pv(v) {{ for(auto &x : v) pf(x); } br;}
#define pvv(mat) { for(auto &r : mat) pv(r); }
#define iv(v) { for(auto &x : v) cin >> x; }

vec vis, Time, low, dp, bridges;
vv g;
int timer = 0;

void dfs(int u, int p)
{
    vis[u] = 1;
    dp[u] = 1;
    Time[u] = low[u] = timer++;
    for (ll v : g[u])
    {
        if (v == p)
            continue;
        if (!vis[v])
        {
            dfs(v, u);
            dp[u] += dp[v];
            low[u] = min(low[u], low[v]);
            if (low[v] > Time[u])
                bridges.push_back(v);
        }
        else
            low[u] = min(low[u], Time[v]);
    }
}

ll solve()
{
    ll n = II, m = II, ans = (n * (n - 1)) / 2;
    bridges.clear();
    g = vv(n);
    for (int i = 0; i < m; i++) {
        int u = II - 1, v = II - 1;
        g[u].push_back(v);
        g[v].push_back(u);
    }

    timer = 1;
    Time = low = dp = vis = vec(n, 0);
    dfs(0, -1);

    for (ll &r : bridges) {
        ll a = dp[r], b = n - a;
        ans = min(ans, ((a * (a - 1)) / 2) + ((b * (b - 1)) / 2));
    }
    return ans;
}

int main()
{
    fast;
    int tc = II;
    while (tc--)
        pl(solve());
    return 0;
}