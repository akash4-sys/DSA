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

int dirs[4][2] = {{1,0},{0,1},{-1,0},{0,-1}};

vv solve()
{
    int n = II, m = II;
    vv v(n, vec(m));
    for (auto &r : v)
        iv(r);
    
    for (int i = 0; i < n; i++)
        for (int j = 0; j < m; j++)
        {
            ll res = 1, k = 0;
            for (auto d : dirs)
            {
                ll x = i + d[0], y = j + d[1];
                if (x >= 0 && x < v.size() && y >= 0 && y < v[0].size())
                    res &= (v[i][j] > v[x][y]), k = max(k, v[x][y]);
            }
            if (res)
                v[i][j] = k;
        }
    return v;
}

int main()
{
    fast;
    int tc = II;
    while (tc--)
    {
        auto v = solve();
        for (auto &r : v)
            pv(r);
    }
    return 0;
}