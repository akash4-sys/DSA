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

int solve()
{
    int n = II;
    vv g(n);
    for (int i = 0; i < n; i++)
    {
        int u = II - 1, v = II - 1;
        g[u].push_back(v);
        g[v].push_back(u);
        if (u == v)
            return 0;
    }

    vec vis(n, 0);
    for (int i = 0; i < n; i++)
        if (!vis[i])
        {
            int len = dfs(i, i);
            if (len % 2)
                return 0;
        }
    return 1;
}

int main()
{
    fast;
    int tc = II;
    while (tc--)
        pl((solve() ? "yes" : "no"));
    return 0;
}