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
    ll n = LL, p = 0, vs = 0;
    vec v(n);
    iv(v);
    ll m = LL;
    vec qr(m);
    iv(qr);

    unordered_map<int, int> mp;
    for (int i = 0; i < n; i++)
        mp[v[i]] = i;

    sort(all(v));
    for (ll q : qr)
    {
        int i = lower_bound(all(v), q) - v.begin();
        i = mp[v[i]];
        vs += i + 1;
        p += n - i;
    }
    cout << vs << " " << p;
}

int main()
{
    fast;
    solve();
    return 0;
}