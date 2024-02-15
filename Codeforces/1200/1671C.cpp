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
    ll n = LL, x = LL, sum = 0, ans = 0, k = 0;
    vec v(n + 1, 0);
    for (int i = 1; i <= n; i++)
        v[i] = LL, sum += v[i];
    
    sort(all(v));
    for (int i = n; i > 0; i--)
    {
        ll csum = sum + (k * i);
        if (csum <= x)
        {
            ll days = (x - csum) / i + 1;
            k += days;
            ans += (days * i);
        }
        sum -= v[i];
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