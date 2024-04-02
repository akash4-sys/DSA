#ifdef __INTELLISENSE__
#include "../../headers.h"
#else
#include <bits/stdc++.h>
using namespace std;
#endif

#define fast ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);

int n, K, mod = 1e9 + 7, dp[2001][2001];

int rec(int k, int i)
{
    if (k == 0)
        return 1;
    if (dp[k][i] != -1)
        return dp[k][i];
    
    int res = 0;
    for (int j = i; j <= n; j += i)
        (res += rec(k - 1, j)) %= mod;
    return dp[k][i] = res;
}

int main()
{
    fast;
    cin >> n >> K;
    memset(dp, -1, sizeof(dp));
    cout << rec(K, 1);
    return 0;
}