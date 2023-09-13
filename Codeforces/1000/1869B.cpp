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
#define pv(v) { for(auto &x : v) pf(x)<<" "; }
#define pvv(mat) { for(auto &r : mat) {pv(r); br;} }
#define iv(v) { for(auto &x : v) cin >> x; }

ll minDist(vv &v, ll k, ll a)
{
    ll sx = v[a][0], sy = v[a][1], mind = LLONG_MAX;
    for (ll i = 0; i < k; i++)
        mind = min(mind, abs(sx - v[i][0]) + abs(sy - v[i][1]));
    return mind;
}

ll solve()
{
    ll n = II, k = II, a = II - 1, b = II - 1;
    vv v(n);
    for (int i = 0; i < n; i++)
        v[i] = {II, II};
    
    ll dist = abs(v[a][0] - v[b][0]) + abs(v[a][1] - v[b][1]);
    if (k == 0)
        return dist;
    return min(dist, minDist(v, k, a) + minDist(v, k, b));
}

int main()
{
    fast;
    int tc = II;
    while (tc--)
        pl(solve());
    return 0;
}