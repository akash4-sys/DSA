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

ll solve()
{
    ll n = LL, m = LL;
    vec a(n), b(m);
    iv(a); iv(b);
    sort(all(a)), sort(all(b));

    ll x = 0, y = n - 1, p = 0, q = m - 1, ans = 0;
    while (x <= y)
    {
        ll d1 = abs(a[x] - b[p]), d2 = abs(a[x] - b[q]);
        ll d3 = abs(a[y] - b[p]), d4 = abs(a[y] - b[q]);
        ll mx = max({d1, d2, d3, d4});
        if (mx == d1)
            ans += d1, x++, p++;
        else if (mx == d2)
            ans += d2, x++, q--;
        else if (mx == d3)
            ans += d3, y--, p++;
        else
            ans += d4, y--, q--;
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