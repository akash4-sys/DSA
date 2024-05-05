#ifdef __INTELLISENSE__
#include "../../headers.h"
#else
#include <bits/stdc++.h>
using namespace std;
#endif

#define ll long long
#define fast ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
#define II ({ int a; cin>>a; a; })

int main()
{
    fast;
    int n = II;
    vector<int> v(n + 1, 0);
    for (int i = 1; i <= n; i++)
        v[i] = II;
    
    vector<vector<ll>> dp(n + 1, vector<ll>(n + 1, 0));
    for (int i = 1; i <= n; i++)
        for (int k = 1; k <= n; k++)
            if (dp[i - 1][k - 1] + v[i] >= 0)
                dp[i][k] = max(dp[i - 1][k], dp[i - 1][k - 1] + v[i]);
            else
                dp[i][k] = dp[i - 1][k];
    
    for (int i = 1; i <= n; i++) {
        for (int k = 1; k <= n; k++)
            cout << dp[i][k] << " ";
        cout << endl;
    }

    for (int i = n; i >= 0; i--)
        if (dp[n][i] >= 0) {
            cout << i;
            break;
        }
    return 0;
}