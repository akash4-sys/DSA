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

vec solve()
{
    int n = II, mex = 0;
    vec a(n), vis(n + 1, 0), p(n, 0);
    iv(a);
    for (int i = 0; i < n; i++)
    {
        p[i] = a[i] > 0 ? mex : mex - a[i];
        vis[p[i]] = 1;
        while (vis[mex])
            mex++;
    }
    return p;
}

int main()
{
    fast;
    int tc = II;
    while (tc--)
        pv(solve());
    return 0;
}