#include <bits/stdc++.h>
using namespace std;

int main()
{
    int a, b;
    cin >> a >> b;
    vector<vector<int>> dp(a + 1, vector<int>(b + 1, INT_MAX));
    for (int i = 0; i <= min(a, b); i++)
        dp[i][i] = 0;
    
    for (int i = 1; i <= a; i++)
        for (int j = 1; j <= b; j++)
            for (int k = 1; k < max(i, j); k++)
            {
                int res = dp[i][j];
                if (k < i)
                    res = min(res, dp[k][j] + dp[i - k][j] + 1);
                if (k < j)
                    res = min(res, dp[i][k] + dp[i][j - k] + 1);
                dp[i][j] = res;
            }
    cout << dp[a][b];
    return 0;
}