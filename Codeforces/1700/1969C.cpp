#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define vec vector<int>
#define all(v) v.begin(), v.end()
#define fast ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
#define II ({ int a; cin>>a; a; })
#define pf(x) cout << x << " "
#define pl(x) cout << x << "\n"
#define br cout << "\n"
#define pv(v) {{ for(auto &x : v) pf(x); } br;}
#define pvv(mat) { for(auto &r : mat) pv(r); }
#define iv(v) { for(auto &x : v) cin >> x; }

ll solve()
{
    int n = II, k = II;
    vec v(n);
    iv(v);
    vector<vector<ll>> dp(n + 1, vector<ll>(k + 1, LLONG_MAX));
    dp[0][0] = 0;
    for (int i = 0; i < n; i++)
        for (int j = 0; j <= k; j++)
        {
            ll x = LLONG_MAX;
            for (int d = 0; j + d <= k && i + d < n; ++d) {
                x = min(x, (ll)v[i + d]);
                dp[i + d + 1][j + d] = min(dp[i + d + 1][j + d], dp[i][j] + (d + 1) * x);
            }
        }
    return *min_element(dp[n].begin(), dp[n].end());
}

int main()
{
    fast;
    for (int tc = II; tc; tc--)
        pl(solve());
    return 0;
}