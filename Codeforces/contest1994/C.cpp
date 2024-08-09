#include <bits/stdc++.h>

using namespace std;

#define ll long long
#define fast ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
#define II ({ int a; cin>>a; a; })

ll solve()
{
    ll n = II, x = II;
    vector<ll> v = {0}, dp(n + 2, 0);
    for (int i = 0; i < n; i++)
        v.push_back(v.back() + II);

    for (int i = n - 1; i >= 0; i--) {
        int j = upper_bound(v.begin(), v.end(), v[i] + x) - v.begin();
        dp[i] = dp[j] + (j - i - 1);
    }
    return accumulate(dp.begin(), dp.end(), 0LL);
}

int main()
{
    fast;
    int tc = II;
    while (tc--)
        cout << solve() << "\n";
    return 0;
}