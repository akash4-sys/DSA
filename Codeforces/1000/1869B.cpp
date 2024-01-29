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

ll solve()
{
    ll n = LL, k = LL, a = LL - 1, b = LL - 1, da = 1e10, db = da;
    vv v(n);
    for (int i = 0; i < n; i++)
        v[i] = {LL, LL};
    
    ll dist = abs(v[a][0] - v[b][0]) + abs(v[a][1] - v[b][1]);
    for (ll i = 0; i < k; i++) {
        da = min(da, abs(v[a][0] - v[i][0]) + abs(v[a][1] - v[i][1]));
        db = min(db, abs(v[b][0] - v[i][0]) + abs(v[b][1] - v[i][1]));
    }
    return min(dist, da + db);
}

int main()
{
    fast;
    int tc = II;
    while (tc--)
        pl(solve());
    return 0;
}