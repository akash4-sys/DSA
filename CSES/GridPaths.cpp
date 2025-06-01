#include <bits/stdc++.h>
using namespace std;

int main()
{
    int n, mod = 1e9 + 7;
    cin >> n;
    char c;
    vector<vector<int>> dp(n + 1, vector<int>(n + 1, 0));
    dp[0][1] = 1;
    for (int i = 1; i <= n; i++)
        for (int j = 1; j <= n; j++) {
            cin >> c;
            if (c == '.')
                dp[i][j] = (0LL + dp[i][j] + dp[i - 1][j] + dp[i][j - 1]) % mod;
        }
    cout << dp[n][n];
    return 0;
}