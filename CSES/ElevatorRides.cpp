#include <bits/stdc++.h>
using namespace std;

int main()
{
    int n, x;
    cin >> n >> x;
    vector<int> v(n);
    for (int &a: v)
        cin >> a;
    
    vector<pair<int, int>> dp(1 << n);
    dp[0] = {1, 0};
    for (int mask = 1; mask < (1 << n); mask++)
    {
        dp[mask] = {21, 0};
        for (int i = 0; i < n; i++)
            if (mask & (1 << i))
            {
                auto [cnt, wt] = dp[mask ^ (1 << i)];
                if (wt + v[i] > x)
                    cnt++, wt = min(wt, v[i]);
                else
                    wt += v[i];
                dp[mask] = min(dp[mask], {cnt, wt});
            }
    }
    cout << dp[(1 << n) - 1].first;
    return 0;
}