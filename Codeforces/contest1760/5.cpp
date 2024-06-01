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
    ll n = II, total = 0, zeros = 0, ans = 0, one = 0;
    vec a(n), sf(n);
    iv(a);
    for (int i = n - 1; i >= 0; i--)
        zeros += (a[i] == 0), sf[i] = zeros;
    
    for (int i = 0; i < n; i++)
        if (a[i])
            total += sf[i];
    
    ans = total;
    for (int i = 0; i < n; i++)
        if (a[i])
            ans = max(ans, total - sf[i] + one), one++;
        else
            ans = max(ans, total - one + sf[i] - 1);
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