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

vec even(ll l, ll r)
{
    l += (l % 2 != 0);
    l += l == 2 ? 2 : 0;
    if (l > r)
        return {-1};
    return {l / 2, l / 2};
}

vec odd(ll n)
{
    for (ll i = 2, sq = sqrt(n); i <= sq && i <= (n - i); i++)
        if ((n - i) % i == 0)
            return {i, n - i};
    return {-1};
}

vec solve()
{
    ll l = LL, r = LL;
    vec ans = even(l, r);
    if (ans[0] != -1)
        return ans;
    return odd(l);
}

int main()
{
    fast;
    int tc = II;
    while (tc--) {
        pv(solve());
        br;
    }
    return 0;
}