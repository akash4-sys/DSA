#include <bits/stdc++.h>
using namespace std;

int mod = 1e9 + 7;
int n, m, dp[1001][1025];

void rec(int i, int j, int mask, int newMask)
{
    if (i == n) {
        dp[j + 1][newMask] = (dp[j + 1][newMask] + dp[j][mask]) % mod;
        return;
    }

    if (mask & (1 << i)) {
        rec(i + 1, j, mask, newMask);
        return;
    }

    if (i + 1 < n && !(mask & (1 << (i + 1))))
        rec(i + 2, j, mask, newMask);
    if (j + 1 < m)
        rec(i + 1, j, mask, newMask | (1 << i));
}

int main()
{
    cin >> n >> m;
    memset(dp, 0, sizeof(dp));
    dp[0][0] = 1;
    for (int i = 0; i < m; i++)
        for (int mask = 0; mask < (1 << n); mask++)
            rec(0, i, mask, 0);
    cout << dp[m][0];
    return 0;
}