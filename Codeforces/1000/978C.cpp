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

void solve()
{
    ll n = LL, m = LL, sum = 0;
    vec a(n), p;
    iv(a);
    vec b(m);
    iv(b);

    for (ll x : a)
    {
        sum += x;
        p.push_back(sum);
    }

    for (ll x : b)
    {
        ll i = lower_bound(all(p), x) - p.begin();
        ll st = p[i] - a[i] + 1;
        ll room = x - st + 1;
        pf(i + 1) << room << endl;
    }
}

int main()
{
    fast;
    solve();
    return 0;
}