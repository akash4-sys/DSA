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
    ll x = II, y = II, k = II;
    map<ll, ll> mp;
    while (k)
    {
        x++;
        ll d = ((y - (x % y)) % y) + 1;
        if (d > k)
            return x + k - 1;

        k -= d;
        x += d - 1;
        if (mp.count(x)) {
            k %= (x - mp[x]);
            return mp[x] + k;
        }
        
        ll org = x;
        while (x % y == 0)
            x /= y;
        mp[org] = x;
    }
    return x;
}

int main()
{
    fast;
    int tc = II;
    while (tc--)
        pl(solve());
    return 0;
}