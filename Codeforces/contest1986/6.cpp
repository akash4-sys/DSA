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
#define SS ({ string s; cin>>s; s; })
#define pf(x) cout << x << " "
#define pl(x) cout << x << endl
#define br cout << endl
#define pv(v) {{ for(auto &x : v) pf(x); } br;}
#define pvv(mat) { for(auto &r : mat) pv(r); }
#define iv(v) { for(auto &x : v) cin >> x; }

class Tarjan
{
    vec vis, Time, low, par;
    vv g, ans;
    int timer = 0;
    void dfs(int u)
    {
        vis[u] = 1;
        Time[u] = low[u] = timer++;
        for (ll v : g[u])
            if (!vis[v])
            {
                par[v] = u;
                dfs(v);
                low[u] = min(low[u], low[v]);
                if (low[v] > Time[u])
                    ans.push_back({u, v});
            }
            else if (v != par[u])
                low[u] = min(low[u], Time[v]);
    }

public:
    vv func(int n, vv &g)
    {
        this->g = g;
        vis = vec(n, 0);
        Time = low = par = vec(n, -1);
        for (int i = 0; i < n; i++)
            if (!vis[i])
                dfs(i);
        return ans;
    }
};

ll solve()
{
    ll n = II, m = II, ans = (n * (n - 1)) / 2;
    vv g(n);
    for (int i = 0; i < m; i++) {
        int u = II - 1, v = II - 1;
        g[u].push_back(v);
        g[v].push_back(u);
    }

    Tarjan t;
    vv bridges = t.func(n, g);

    vec v(n, 0), vis(n, 0);
    function<int(int)> dfs = [&](int u) -> int {
        vis[u] = 1;
        v[u] += 1;
        for (ll &c : g[u])
            if (!vis[c])
                v[u] += dfs(c);
        return v[u];
    };

    for (auto &r : bridges) {
        ll a = v[r[0]], b = n - v[r[0]];
        cout << a << " " << b << endl;
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