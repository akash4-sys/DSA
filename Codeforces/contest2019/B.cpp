#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define vec vector<ll>
#define vv vector<vec>
#define all(v) v.begin(), v.end()
#define fast ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
#define II ({ int a; cin>>a; a; })
#define LL ({ ll a; cin>>a ; a; })
#define SS ({ string s; cin>>s; s; })
#define pf(x) cout << x << " "
#define pl(x) cout << x << "\n"
#define br cout << "\n"
#define pyn(x) cout << (x ? "YES" : "NO") << "\n"
#define pv(v) {{ for(auto &x : v) pf(x); } br;}
#define pvv(mat) { for(auto &r : mat) pv(r); }
#define iv(v) { for(auto &x : v) cin >> x; }

void solve()
{
    ll n = II, q = II;
    vec ans, v(n);
    iv(v);
    map<ll, ll> mp;
    for (int i = 0; i < n - 1; i++)
        if (v[i] + 1 <= v[i + 1] - 1)
        {
            ll cnt = v[i + 1] - v[i] - 1;
            ll segs = (i + 1) * (n - i - 1);
            mp[segs] += cnt;
        }

    for (int i = 0; i < n; i++)
        mp[(i * (n - i)) + (n - i - 1)]++;

    while (q--) {
        ll k = LL;
        cout << (mp.count(k) ? mp[k] : 0) << " ";
    }
    br;
}

int main()
{
    fast;
    for (int tc = II; tc; tc--)
        solve();
    return 0;
}