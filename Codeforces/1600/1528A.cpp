#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define fast ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
#define II ({ int a; cin>>a; a; })
#define LL ({ ll a; cin>>a ; a; })
#define pf(x) cout << x << " "
#define pl(x) cout << x << "\n"
#define br cout << "\n"
#define pyn(x) cout << (x ? "YES" : "NO") << "\n"
#define pv(v) {{ for(auto &x : v) pf(x); } br;}
#define pvv(mat) { for(auto &r : mat) pv(r); }

ll solve()
{
    int n = II;
    vector<vector<int>> wt(n), g(n);
    for (auto &w : wt)
        w = {II, II};
    for (int i = 1; i < n; i++) {
        int u = II - 1, v = II - 1;
        g[u].push_back(v);
        g[v].push_back(u);
    }

    vector<vector<ll>> dp(n, vector<ll>(2, -1));
    auto dfs = [&](auto &&dfs, int u, int i, int par) -> ll {
        if (dp[u][i] != -1)
            return dp[u][i];

        ll res = 0;
        for (int v : g[u])
            if (v != par) 
            {
                ll val = 0;
                for (int j = 0; j < 2; j++)
                    val = max(val, dfs(dfs, v, j, u) + abs(wt[u][i] - wt[v][j]));
                res += val;
            }
        return dp[u][i] = res;
    };
    return max(dfs(dfs, 0, 0, -1), dfs(dfs, 0, 1, -1));
}

int main()
{
    fast;
    for (int tc = II; tc; tc--)
        pl(solve());
    return 0;
}