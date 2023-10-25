#ifdef __INTELLISENSE__
#include "../../headers.h"
#else
#include <bits/stdc++.h>
using namespace std;
#endif

#define ll long long
#define vec vector<int>
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
#define pv(v) { for(auto &x : v) pf(x)<<" "; }
#define pvv(mat) { for(auto &r : mat) {pv(r); br;} }
#define iv(v) { for(auto &x : v) cin >> x; }

int rec(vec &v, vec &dp, int i)
{
    if (i >= v.size())
        return 0;
    if (dp[i] != -1)
        return dp[i];
    
    int res = 2e5 + 5;
    if (i + v[i] < v.size())
        res = rec(v, dp, v[i] + i + 1);
    return dp[i] = min(res, rec(v, dp, i + 1) + 1);
}

int solve()
{
    int n = II;
    vec v(n), dp(n, -1);
    iv(v);
    return rec(v, dp, 0);
}

int main()
{
    fast;
    int tc = II;
    while (tc--)
        pl(solve());
    return 0;
}