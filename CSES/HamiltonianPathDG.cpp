#include <bits/stdc++.h>
using namespace std;
#define II ({ int a; cin>>a ; a; })

int main()
{
    int n = II, m = II, mod = 1e9 + 7;
    vector<vector<int>> g(n);
    while (m--) {
        int u = II - 1, v = II -  1;
        g[u].push_back(v);
    }
    
    vector<vector<int>> dp(1 << n, vector<int>(n, 0));
    dp[1][0] = 1;
    for (int mask = 2; mask < (1 << n); mask++)
    {
        if (!(mask & 1) || (mask & (1 << (n - 1)) && mask != (1 << n) - 1))
            continue;
        for (int u = 0; u < n; u++)
            if (mask & (1 << u))
                for (int v : g[u])
                    if (mask & (1 << v))
                        dp[mask][v] = (dp[mask][v] + dp[mask ^ (1 << v)][u]) % mod;
    }
    cout << dp[(1 << n) - 1][n - 1];        // count of hamiltonian paths
    return 0;
}
