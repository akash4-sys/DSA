#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define vec vector<ll>
#define vv vector<vec>
#define vvv vector<vv>
#define fast ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
#define II ({ int a; cin>>a; a; })
#define LL ({ ll a; cin>>a ; a; })
#define pl(x) cout << x << "\n"

ll mod = 1e9 + 7;

ll rec(vvv &dp, int n, int k, int i, int dir)
{
    if (k == 1)
        return 1;
    if (dp[i][k][dir] != -1)
        return dp[i][k][dir];
    
    ll res = 2;
    if (dir == 1) {
        if (i < n)
            (res += rec(dp, n, k, i + 1, dir) - 1) %= mod;
        if (i > 1)
            (res += rec(dp, n, k - 1, i - 1, !dir) - 1) %= mod;
    }
    else {
        if (i > 1)
            (res += rec(dp, n, k, i - 1, dir) - 1) %= mod;
        if (i < n)
            (res += rec(dp, n, k - 1, i + 1, !dir) - 1) %= mod;
    }
    return dp[i][k][dir] = res;
}

int main()
{
    fast;
    for (int tc = II; tc; tc--) {
        ll n = LL, k = LL;
        vvv dp(n + 1, vv(k + 1, vec(2, -1)));
        pl(rec(dp, n, k, 1, 1));
    }
    return 0;
}