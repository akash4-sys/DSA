#ifdef __INTELLISENSE__
#include "../../headers.h"
#else
#include <bits/stdc++.h>
using namespace std;
#endif

#define fast ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
#define II ({ int a; cin>>a; a; })

int solve()
{
    int n = II;
    vector<int> v(n), dp(n + 1, 0);
    for (int &a : v)
        a = II;
    
    for (int i = n - 1; i >= 0; i--)
    {
        dp[i] = dp[i + 1];
        if (i + v[i] < n)
            dp[i] = max(dp[i], dp[i + v[i] + 1] + v[i] + 1);
    }
    return n - dp[0];
}

int main()
{
    fast;
    int tc = II;
    while (tc--)
        cout << solve() << "\n";
    return 0;
}