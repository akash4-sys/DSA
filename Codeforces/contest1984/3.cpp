

#ifdef __INTELLISENSE__
#include "../../headers.h"
#else
#include <bits/stdc++.h>
using namespace std;
#endif

#define ll long long
#define vec vector<ll>
#define fast ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
#define II ({ int a; cin>>a; a; })
#define pl(x) cout << x << endl
#define iv(v) { for(auto &x : v) cin >> x; }

ll solve()
{
    int n = II;
    vec v(n);
    iv(v);

    vv dp(n + 1, vec(2, 0));
    for (int i = 1; i <= n; i++) {
        dp[i][0] = min(dp[i - 1][0] + v[i - 1], dp[i - 1][1] + v[i - 1]);
        dp[i][1] = max(abs(dp[i - 1][0] + v[i - 1]), abs(dp[i - 1][1] + v[i - 1]));
    }
    return max(abs(dp[n][0]), abs(dp[n][1]));
}

int main()
{
    fast;
    int tc = II;
    while (tc--)
        pl(solve());
    return 0;
}