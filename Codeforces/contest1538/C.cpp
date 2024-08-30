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
#define pl(x) cout << x << "\n"
#define br cout << "\n"
#define pv(v) {{ for(auto &x : v) pf(x); } br;}
#define pvv(mat) { for(auto &r : mat) pv(r); }
#define iv(v) { for(auto &x : v) cin >> x; }

ll solve()
{
    ll n = II, l = II, r = II, ans = 0;
    vec v(n);
    iv(v);
    sort(all(v));

    for (ll &a : v)
        if (a < r)
        {
            ll i = lower_bound(all(v), max(l - a, 0LL)) - v.begin();
            ll j = upper_bound(all(v), r - a) - v.begin() - 1;
            if (i <= j) {
                ans += (j - i + 1);
                if (l <= a * 2 && a * 2 <= r)
                    ans = max(ans - 1, 0LL);
            }
        }
    return ans / 2;
}

int main()
{
    fast;
    for (int tc = II; tc; tc--)
        pl(solve());
    return 0;
}