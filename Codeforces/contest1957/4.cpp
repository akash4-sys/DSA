#ifdef __INTELLISENSE__
#include "../../headers.h"
#else
#include <bits/stdc++.h>
using namespace std;
#endif

#define ll long long
#define vec vector<int>
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

int root = -1;

int dist(vv &g, vec &path, int b, int u, int par)
{
    path.push_back(u);
    if (u == b)
    {
        int d = path.size(), at = ((d + 1) / 2) - 1;
        root = path[at];
        return at + 1;
    }

    for (int &v : g[u])
        if (par != v)
        {
            int d = dist(g, path, b, v, u);
            if (d != 0)
                return d;
        }
    path.pop_back();
    return 0;
}

int dfs(vv &g, vec &deg, int a, int u, int par)
{
    int len = 0;
    for (int &v : g[u])
        if (par != v)
        {
            if (v == a)
                return 0;
            if (deg[v] > 4)
                return 1;
            len += dfs(g, deg, a, v, u) + 1;
        }
    return len;
}

ll solve()
{
    int n = II, a = II - 1, b = II - 1;
    root = -1;
    vv g(n);
    vec deg(n, 0);
    for (int i = 0; i < n - 1; i++) {
        int u = II - 1, v = II - 1;
        g[u].push_back(v);
        g[v].push_back(u);
        deg[u]++;
        deg[v]++;
    }

    vec path;
    int cost = dist(g, path, b, a, -1), len = 0;
    for (int i = 0; i < n; i++)
        if (deg[i] == 2)
            len = max(len, dfs(g, deg, root, i, -1));
    
    pl(root);
    return (n - 1) * 2 + cost - len;
}

int main()
{
    fast;
    int tc = II;
    while (tc--)
        pl(solve());
    return 0;
}