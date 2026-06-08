#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define fast ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
#define II ({ int a; cin>>a; a; })

ll mod = 1e9 + 7;
ll dp[1001][1001][2];

ll rec(int n, int k, int i, int d)
{
    if (i < 1 || i > n || k == 1)
        return 0;
    if (dp[i][k][d] != -1)
        return dp[i][k][d];
    
    ll res = 0;
    if (d)
        res = (rec(n, k, i + 1, 1) + rec(n, k - 1, i - 1, 0) + 1) % mod;
    else
        res = (rec(n, k, i - 1, 0) + rec(n, k - 1, i + 1, 1) + 1) % mod;
    return dp[i][k][d] = (res % mod);
}

int main()
{
    fast;
    for (int tc = II; tc; tc--) {
        int n = II, k = II;
        memset(dp, -1, sizeof(dp));
        cout << rec(n, k, 1, 1) + 1 << "\n";
    }
    return 0;
}