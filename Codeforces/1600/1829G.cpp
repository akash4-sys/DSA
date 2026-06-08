#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define fast ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
#define II ({ int a; cin >> a; a; })

int main()
{
    fast;
    const ll N = 1e6;
    vector<ll> dp(N + 1, 0);
    dp[1] = 1;
    for (ll i = 2, n = 2; n <= N; i++)
    {
        dp[n] = dp[n - i + 1] + (n * n);
        n++;

        for (ll l = n + i - 2; n < l; n++)
            dp[n] = dp[n - i + 1] + dp[n - i] - dp[n - 2*i + 2] + (n * n);

        dp[n] = dp[n - i] + (n * n);
        n++;
    }

    for (int t = II; t; t--)
        cout << dp[II] << "\n";
    return 0;
}