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
#define pv(v) {{ for(auto &x : v) pf(x); } br;}
#define pvv(mat) { for(auto &r : mat) pv(r); }
#define iv(v) { for(auto &x : v) cin >> x; }

ll sum(ll n)
{
    if (n < 10) return n * (n + 1) / 2;
    ll d = log10(n);

    ll *a = new ll[d + 1];
    a[0] = 0, a[1] = 45;
    for (ll i = 2; i <= d; i++)
        a[i] = a[i - 1] * 10 + 45 * ceil(pow(10, i - 1));

    ll p = ceil(pow(10, d));
    ll x = n / p;
    return x * a[d] + (x * (x - 1) / 2) * p + x * (1 + n % p) + sum(n % p);
}

ll solve()
{
    ll n = LL;
    return sum(n);
}

int main()
{
    fast;
    int tc = II;
    while (tc--)
        pl(solve());
    return 0;
}