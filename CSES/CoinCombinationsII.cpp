#include <bits/stdc++.h>
using namespace std;

int main()
{
    int n, x, mod = 1e9 + 7;
    cin >> n >> x;
    vector<int> dp(x + 1, 0);
    dp[0] = 1;
    for (int j = 0, c; j < n; j++) {
        cin >> c;
        for (int i = c; i <= x; i++)
            dp[i] = (0LL + dp[i] + dp[i - c]) % mod;
    }
    cout << dp[x];
    return 0;
}