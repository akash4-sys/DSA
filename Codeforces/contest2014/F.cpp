#include <bits/stdc++.h>
using namespace std;

#define fast ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
#define II ({ int a; cin>>a; a; })

int main()
{
    fast;
    for (int tc = II; tc; tc--)
    {
        int n = II, c = II;
        vector<int> a(n);
        for (int &x : a)
            x = II;
        
        vector<vector<long long>> g(n), dp(n, vector<long long>(2, 0));
        for (int i = 1; i < n; i++) {
            int u = II - 1, v = II - 1;
            g[u].push_back(v);
            g[v].push_back(u);
        }

        function<void(int, int)> dfs = [&](int u, int par) -> void {
            for (auto &v : g[u])
                if (v != par) {
                    dfs(v, u);
                    dp[u][0] += max(dp[v][0], dp[v][1]);
                    dp[u][1] += max(dp[v][0], dp[v][1] - (c * 2));
                }
            dp[u][1] += a[u];
        };
        dfs(0, -1);
        cout << max(dp[0][0], dp[0][1]) << "\n";
    }
    return 0;
}