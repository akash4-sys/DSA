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
    ll n = II, ans = 0, even = 0, odd = 0, x = 0, mx = 0;
    vec v(n);
    iv(v);
    for (ll &a : v) {
        if (a % 2)
            odd++, x = max(x, a);
        else
            even++;
        mx = max(mx, a);
    }

    if ((odd && !even) || (even && !odd))
        return 0;
    if (mx % 2)
        return even;
    
    sort(all(v));
    for (ll &a : v)
        if (a % 2 == 0) {
            if (x > a)
                x += a, ans++;
            else
                ans = n + 10;
        }
    return min(ans, even + 1);
}

int main()
{
    fast;
    int tc = II;
    while (tc--)
        pl(solve());
    return 0;
}