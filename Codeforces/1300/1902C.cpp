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
    ll n = LL;
    vec a(n);
    iv(a);
    if (n == 1)
        return 1;

    set<ll> st(all(a));
    ll m = *st.rbegin(), x = 0, ans = 0;
    for (ll k : a)
        if (k != m)
            x = gcd(x, m - k);

    for (ll k : a)
        ans += ((m - k) / x);
    
    for (ll i = 1; i <= n; i++)
        if (st.find(m - (x * i)) == st.end())
            return ans + i;
    return ans + n;
}

int main()
{
    fast;
    int tc = II;
    while (tc--)
        pl(solve());
    return 0;
}