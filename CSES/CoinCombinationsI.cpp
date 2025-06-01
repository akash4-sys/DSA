#include <bits/stdc++.h>
using namespace std;

int main()
{
    int n, x, mod = 1e9 + 7;
    cin >> n >> x;
    vector<int> dp(x + 1, 0), coins(n);
    dp[0] = 1;
    for (int &c : coins)
        cin >> c;

    for (int i = 0; i <= x; i++)
        for (int &c : coins)
            if (i >= c)
                dp[i] = (0LL + dp[i] + dp[i - c]) % mod;
    cout << dp[x];
    return 0;
}