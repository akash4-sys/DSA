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
    ll x = LL, y = LL, z = LL, k = LL, ans = 0;
    vec v = {x, y, z};
    sort(all(v), greater<ll>());
    x = v[0], y = v[1], z = v[2];

    for (ll i = 1; i <= z; i++)
        for (ll j = 1; j <= y; j++)
            if (k % (i * j) == 0 && k / (i * j) <= x)
            {
                ll a = x - (k / (i * j)) + 1;
                ll b = y - j + 1;
                ll c = z - i + 1;
                ans = max(ans, a * b * c);
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