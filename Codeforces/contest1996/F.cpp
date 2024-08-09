

#include <bits/stdc++.h>

using namespace std;

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
    ll n = II, k = II, ans = 0, l = 0, r = 1e9 + 1, gx = 0;
    vec a(n), b(n);
    iv(a); iv(b);

    while (l <= r)
    {
        ll x = l + ((r - l) / 2), terms = 0;
        for (int i = 0; i < n; i++)
            if (a[i] >= x)
                terms += (a[i] - x) / b[i] + 1;

        if (terms >= k)
            l = x + 1, gx = max(gx, x);
        else
            r = x - 1;
    }

    ll terms = 0;
    for (int i = 0; i < n; i++)
        if (a[i] >= gx) {
            ll m = (a[i] - gx) / b[i] + 1;
            ans += m * a[i] - ((m * (m - 1) / 2) * b[i]);
            terms += m;
        }
    return ans - ((terms - k) * gx);
}

int main()
{
    fast;
    int tc = II;
    while (tc--)
        pl(solve());
    return 0;
}