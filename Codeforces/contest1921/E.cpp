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
#define pv(v) { for(auto &x : v) pf(x); }
#define pvv(mat) { for(auto &r : mat) {pv(r); br;} }
#define iv(v) { for(auto &x : v) cin >> x; }

ll distance(ll x1, ll y1, ll x2, ll y2) {
    ll dx = abs(x2 - x1);
    ll dy = abs(y2 - y1);

    ll mn = min(dx, dy);
    ll mx = max(dx, dy);

    ll ds = mn;
    ll ss = mx - mn;
    return ds + ss - 1;
}

string solve()
{
    ll n = LL, m = LL, x1 = LL, y1 = LL, x2 = LL, y2 = LL;
    ll d = distance(x1, y1, x2, y2);
    if (x2 < x1 || n < m)
        return "Draw";
    if (d % 2 == 0)
        return "Alice";
    return "Bob";
}

int main()
{
    fast;
    int tc = II;
    while (tc--)
        pl(solve());
    return 0;
}