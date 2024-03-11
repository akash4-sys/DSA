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

ll sum(ll n) { return (n * (n + 1LL)) / 2LL; }

ll solve()
{
    ll k = LL, x = LL, a = 0, b = 0;
    for (ll l = 1, r = k; l <= r;)
    {
        ll n = (r - l) / 2LL + l;
        if (sum(n) <= x)
            l = n + 1, a = max(a, n);
        else
            r = n - 1;
    }

    a += (sum(a) < x && a < k);
    if (a < k)
        return a;
    
    x -= sum(a), k--;
    for (ll l = 1, r = k; l <= r;)
    {
        ll n = (r - l) / 2LL + l;
        ll emotes = sum(k) - sum(k - n);
        if (emotes <= x)
            l = n + 1, b = max(b, n);
        else
            r = n - 1;
    }
    b += (sum(k) - sum(k - b) < x && b < k);
    return a + b;
}

int main()
{
    fast;
    int tc = II;
    while (tc--)
        pl(solve());
    return 0;
}