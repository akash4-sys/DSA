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
#define pv(v) { for(auto &x : v) pf(x)<<" "; }
#define pvv(mat) { for(auto &r : mat) {pv(r); br;} }
#define iv(v) { for(auto &x : v) cin >> x; }

ll solve()
{
    ll n = LL;
    vector<ll> v(400, LLONG_MAX);
    for (ll i = 0; i < n; i++) {
        ll d = LL, s = LL;
        v[d - 1] = min(v[d - 1], s + d - 1);
    }

    ll ans = 0;
    for (ll i = 0; i < 400; i++)
    {
        ll flag = 1;
        for (ll j = i - 1, t = i + 1; j >= 0; j--, t++)
            if (t >= v[j]) {
                flag = 0;
                break;
            }
        if (!flag)
            return ans;
        ans = i + 1;
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