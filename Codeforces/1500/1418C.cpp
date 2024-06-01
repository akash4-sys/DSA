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
#define pv(v) {{ for(auto &x : v) pf(x); } br;}
#define pvv(mat) { for(auto &r : mat) pv(r); }
#define iv(v) { for(auto &x : v) cin >> x; }

int dp[200001][2];
int rec(vec &a, int i, int t)
{
    if (i >= a.size())
        return 0;
    if (dp[i][t] != -1)
        return dp[i][t];
    
    if (!t) {
        int res = rec(a, i + 1, 1) + a[i];
        if (i + 1 < a.size())
            res = min(res, rec(a, i + 2, 1) + a[i] + a[i + 1]);
        return dp[i][t] = res;
    }
    return dp[i][t] = min(rec(a, i + 1, 0), rec(a, i + 2, 0));
}

int solve()
{
    int n = II;
    vector<int> a(n);
    iv(a);
    memset(dp, -1, sizeof(dp));
    return rec(a, 0, 0);
}

int main()
{
    fast;
    int tc = II;
    while (tc--)
        pl(solve());
    return 0;
}