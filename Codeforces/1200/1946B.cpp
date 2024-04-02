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

ll kadane(vec &nums)
{
    ll maxSum = INT_MIN, sum = 0;
    for (ll n : nums)
    {
        maxSum = max(maxSum, sum + n);
        sum = max(sum + n, 0LL);
    }
    return maxSum;
}

ll solve()
{
    ll n = LL, k = LL, mod = 1e9 + 7, neg = 0;
    vec v(n);
    iv(v);
    ll total = accumulate(all(v), 0LL);
    for (ll a : v)
        neg += (a < 0);
    
    if (neg == n)
        return (total % mod + mod) % mod;

    ll s = kadane(v), r = total - s;
    for (int i = 0; i < k; i++)
        s = (s * 2LL) % mod;
    return ((s % mod + mod) % mod + ((r % mod) + mod) % mod) % mod;
}

int main()
{
    fast;
    int tc = II;
    while (tc--)
        pl(solve());
    return 0;
}