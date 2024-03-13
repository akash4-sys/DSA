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

// ! dp does not reach last elememt
// ! how to fix that?

ll rec(vec &a, vec &dp, ll d, int i)
{
    ll m = a.size();
    if (i == m)
        return 0;
    if (dp[i] != -1)
        return dp[i];
    
    ll res = LLONG_MAX;
    for (int j = i; j < m && j - i <= d; j++)
        res = min(res, rec(a, dp, d, j + 1) + a[j] + 1);
    return dp[i] = res;
}

ll solve()
{
    ll n = LL, m = LL, k = LL, d = LL;
    vv v(n, vec(m));
    for (auto &r : v)
        iv(r);
    
    vec cost;
    for (auto &r : v) {
        vec dp(m, -1);
        cost.push_back(rec(r, dp, d, 0));
    }

    ll sum = 0, ans = 0;
    for (int i = 0; i < k; i++)
        sum += cost[i];
    
    ans = sum;
    for (int i = 1; i < n - k + 1; i++) {
        sum -= cost[i - 1];
        sum += cost[i + k - 1];
        ans = min(ans, sum);
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