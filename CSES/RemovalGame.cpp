#include <bits/stdc++.h>
using namespace std;
 
int main()
{
    int n;
    cin >> n;
    vector<long long> v(n);
    for (auto &a : v)
        cin >> a;
 
    long long dp[n + 1][n + 1][2];
    memset(dp, 0, sizeof(dp));
    for (int i = n - 1; i >= 0; i--)
        for (int j = i; j < n; j++)
            for (int x = 0; x < 2; x++)
                if (x)
                    dp[i][j + 1][x] = max(dp[i + 1][j + 1][0] + v[i], dp[i][j][0] + v[j]);
                else
                    dp[i][j + 1][x] = min(dp[i + 1][j + 1][1], dp[i][j][1]);
    cout << dp[0][n][1];
    return 0;
}