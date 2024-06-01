#ifdef __INTELLISENSE__
#include "../../headers.h"
#else
#include <bits/stdc++.h>
using namespace std;
#endif

#define fast ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
#define II ({ int a; cin>>a; a; })
#define SS ({ string s; cin>>s; s; })

int solve()
{
    const int n = II;
    vector<vector<int>> g(n + 1);
    for (int i = 2; i <= n; i++)
        g[II].push_back(i);
    string s = '#' + SS;

    int dp[n + 10][3];
    function<void(int)> dfs = [&](int u) -> void {
        dp[u][0] = n + 100;
        dp[u][1] = s[u] == 'S' ? n + 100 : 0;
        dp[u][2] = s[u] == 'P' ? n + 100 : 0;

        int res = 0;
        for (int v : g[u]) {
            dfs(v);
            dp[u][1] += min({dp[v][1], dp[v][2] + 1, dp[v][0]});
            dp[u][2] += min({dp[v][1] + 1, dp[v][2], dp[v][0]});
            res += dp[v][0];
        }

        if (s[u] != 'C')
            res = n + 100;
        dp[u][0] = min({res, dp[u][1] + 1, dp[u][2] + 1});
    };
    dfs(1);
    return min({dp[1][0], dp[1][1], dp[1][2]});
}

int main()
{
    fast;
    int tc = II;
    while (tc--)
        cout << solve() << "\n";
    return 0;
}