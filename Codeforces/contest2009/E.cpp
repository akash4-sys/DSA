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

ll sum(ll k) { return (k * (k + 1)) / 2; }

ll solve()
{
    ll n = II, k = II, l = k, r = n + k - 1, ans = LLONG_MAX;
    while (l <= r) {
        ll m = (l + r) / 2;
        ll a = sum(m) - sum(k - 1), b = sum(n + k - 1) - sum(m);
        ll diff = b - a;
        ans = min(ans, abs(diff));
        if (diff < 0)
            r = m - 1;
        else
            l = m + 1;
    }
    return ans;
}

int main()
{
    fast;
    for (int tc = II; tc; tc--)
        pl(solve());
    return 0;
}