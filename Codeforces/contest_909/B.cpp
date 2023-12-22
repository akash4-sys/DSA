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
#define pv(v) { for(auto &x : v) pf(x); }
#define pvv(mat) { for(auto &r : mat) {pv(r); br;} }
#define iv(v) { for(auto &x : v) cin >> x; }

void factors(int x, vec &v)
{
    for (int i = 1, sq = sqrt(x); i <= sq; i++)
        if (x % i == 0)
        {
            if (x / i != i)
                v.push_back(x / i);
            v.push_back(i);
        }
}

ll solve()
{
    ll n = LL;
    vec v(n), fc, pf;
    iv(v);
    factors(n, fc);
    for (int a : v)
        pf.push_back(pf.size() ? pf.back() + a : a);
    
    ll ans = 0;
    for (int f : fc)
    {
        ll mx = 0, mn = LLONG_MAX;
        for (int i = f - 1; i < v.size(); i += f)
        {
            mx = max(mx, pf[i] - (i - f >= 0 ? pf[i - f] : 0));
            mn = min(mn, pf[i] - (i - f >= 0 ? pf[i - f] : 0));
        }
        ans = max(ans, mx - mn);
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