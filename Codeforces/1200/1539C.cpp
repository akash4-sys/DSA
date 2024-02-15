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

ll solve()
{
    ll n = LL, k = LL, x = LL;
    vec v(n), req;
    iv(v);

    sort(all(v));
    for (int i = 1; i < n; i++)
        if (ll gap = v[i] - v[i - 1]; gap > x)
            req.push_back(gap / x - (gap % x == 0));
    
    int i = 0;
    sort(all(req));
    while (i < req.size() && k - req[i] >= 0)
        k -= req[i++];
    return req.size() - i + 1;
}

int main()
{
    fast;
    pl(solve());
    return 0;
}