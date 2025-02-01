#include <bits/stdc++.h>
using namespace std;

int main()
{
    int n, sum = 0, mod = 998244353;
    cin >> n;
    vector<int> v(n);
    for (int &a : v) {
        cin >> a;
        sum += a;
    }

    vector<long long> dp(sum + 1, 0);
    dp[0] = 1;
    for (int &a : v)
        for (int j = sum - a; j >= 0; --j)
            (dp[j + a] += dp[j]) %= mod;
    
    long long ans = 0;
    for (int i = 0; i <= sum; i++)
        (ans += ((i + 1) / 2) * dp[i]) %= mod;
    
    for (int &a : v)
        for (int j = 0; j < a; j++) {
            long long x = a - ((a + j + 1) / 2);
            (x *= dp[j]) %= mod;
            (ans += x) %= mod;
        }
    cout << ans;
    return 0;
}