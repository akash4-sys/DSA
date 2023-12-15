#ifdef __INTELLISENSE__
#include "../headers.h"
#else
#include <bits/stdc++.h>
using namespace std;
#endif

int main()
{
    int n, x;
    cin >> n >> x;
    vector<int> v(n), dp(x + 1, x + 10);
    for (int i = 0; i < n; i++)
        cin >> v[i];

    dp[0] = 0;
    for (int i = 1; i <= x; i++)
        for (int c : v)
            if (i >= c)
                dp[i] = min(dp[i], 1 + dp[i - c]);
    
    int ans = dp[x] == x + 10 ? -1 : dp[x];
    cout << ans;
    return 0;
}