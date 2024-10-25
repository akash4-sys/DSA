#include <bits/stdc++.h>
using namespace std;

#define fast ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
#define II ({ int a; cin>>a; a; })
#define pyn(x) cout << (x ? "YES" : "NO") << "\n"

bool solve()
{
    int n = II;
    vector<vector<int>> g(n);
    for (int i = 0; i < n; i++) {
        int a = II - 1, b = II - 1;
        g[a].push_back(b);
        g[b].push_back(a);
    }
    
    for (int i = 0; i < n; i++)
        if (g[i].size() != 2)
            return 0;

    vector<int> vis(n, 0);
    auto dfs = [&](auto &&dfs, int u) -> int {
        vis[u] = 1;
        int res = 0;
        for (int v : g[u])
            if (!vis[v])
                res += dfs(dfs, v) + 1;
        return res;
    };

    for (int i = 0; i < n; i++)
        if (!vis[i] && dfs(dfs, i) % 2 == 0)
            return 0;
    return 1;
}

int main()
{
    fast;
    for (int tc = II; tc; tc--)
        pyn(solve());
    return 0;
}