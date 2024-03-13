

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

bool rec(vv &v, vv &dp, int n, int x, int u, int i)
{
    if (i == v.size())
        return u == x;
    if (dp[i][u] != -1)
        return dp[i][u];
    
    if (v[i][1] == 1)
        return dp[i][u] = rec(v, dp, n, x, (u + v[i][0]) % n, i + 1);
    if (v[i][1] == 0)
        return dp[i][u] = rec(v, dp, n, x, ((u - v[i][0]) + n) % n, i + 1);

    bool a = rec(v, dp, n, x, (u + v[i][0]) % n, i + 1);
    bool b = rec(v, dp, n, x, ((u - v[i][0]) + n) % n, i + 1);
    return dp[i][u] =  a || b;
}

void solve()
{
    int n = II, m = II, x = II - 1;
    vv v;
    for (int i = 0; i < m; i++) {
        int r = II;
        char c;
        cin >> c;
        int d = c == '0' ? 0 : (c == '1' ? 1 : 2);
        v.push_back({r, d});
    }
    
    reverse(all(v));
    vec ans;
    vv dp(m + 1, vec(n + 1, -1));
    for (int i = 0; i < n; i++)
        if (rec(v, dp, n, x, i, 0))
            ans.push_back(i + 1);
    
    pl(ans.size());
    pv(ans);
}

int main()
{
    fast;
    int tc = II;
    while (tc--)
        solve();
    return 0;
}