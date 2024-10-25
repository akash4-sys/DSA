#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define vec vector<long double>
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

ll solve()
{
    int n = II;
    vec v(n);
    iv(v);
    if (n <= 2)
        return -1;
    
    sort(all(v));
    ll l = 0, r = 1e18, ans = r + 1, sum = accumulate(all(v), 0LL);
    for (auto &a : v)
        a *= 2LL;

    while (l <= r)
    {
        ll x = (l + r) / 2;
        long double avg = (sum + x) / (n * 1.0);
        ll i = lower_bound(all(v), avg) - v.begin();
        if (i >= 0 && v[i] >= avg)
            i--;
        if (i + 1 > n / 2.0)
            r = x - 1, ans = min(ans, x);
        else
            l = x + 1;
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