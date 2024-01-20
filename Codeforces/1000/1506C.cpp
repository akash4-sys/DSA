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

int n, m, dp[21][21], ans = 0;
string s, r;

int rec(int i, int j)
{
    if (i == n || j == m)
        return 0;
    if (dp[i][j] != -1)
        return dp[i][j];
    
    rec(i + 1, j),
    rec(i, j + 1);
    dp[i][j] = (s[i] == r[j]) ? rec(i + 1, j + 1) + 1 : 0;
    ans = max(ans, dp[i][j]);
    return dp[i][j];
}

int solve()
{
    s = SS, r = SS;
    n = s.size(), m = r.size();
    memset(dp, -1, sizeof(dp));
    ans = 0;
    rec(0, 0);
    return n + m - (ans * 2);
}

int main()
{
    fast;
    int tc = II;
    while (tc--)
        pl(solve());
    return 0;
};