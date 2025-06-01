#include <bits/stdc++.h>
using namespace std;

int main()
{
    int n, total;
    cin >> n >> total;
    vector<int> prices(n), pages(n);
    for (int &p : prices)
        cin >> p;
    for (int &p : pages)
        cin >> p;
    
    vector<vector<int>> dp(n + 1, vector<int>(total + 1, 0));
    for (int i = 0; i < n; i++)
        for (int j = 0; j <= total; j++) {
            dp[i + 1][j] = dp[i][j];
            if (prices[i] <= j)
                dp[i + 1][j] = max(dp[i + 1][j], dp[i][j - prices[i]] + pages[i]);
        }
    cout << dp[n][total];
    return 0;
}