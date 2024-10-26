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

ll solve()
{
    ll n = LL, k = LL, x = LL, sum = 0;
    vec v(n), p;
    iv(v);

    sort(all(v), greater<int>());
    for (ll a : v)
        sum += a, p.push_back(sum);
    
    ll ans = LLONG_MIN;
    for (int i = 0; i <= min(n, k); i++)
    {
        ll r = min(i + x - 1, n - 1);
        ll alice = i ? p[i - 1] : 0;
        ll bob = (p[r] - alice) * 2LL;
        ans = max(ans, sum - bob - alice);
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