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

ll solve()
{
    ll n = LL, x = LL, y = LL;
    vec a(n);
    iv(a);
    ll sum = accumulate(all(a), 0LL);
    ll mind = sum - y, maxd = sum - x;
    if (mind <= 0)
        mind = 0;
    
    sort(all(a));
    ll ans = 0;
    for (int i = 0; i < n; i++)
    {
        ll l = mind - a[i], r = maxd - a[i];
        int j = lower_bound(a.begin() + i + 1, a.end(), l) - a.begin();
        int k = upper_bound(a.begin() + i + 1, a.end(), r) - a.begin() - 1;
        ans += (k - j + 1);
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