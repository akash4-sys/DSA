#include <bits/stdc++.h>
using namespace std;

#define fast ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
#define II ({ int a; cin >> a; a; })
#define pv(v) {{ for(auto &x : v) cout << x << " "; } cout << endl;}

vector<int> lvl;

bool query(vector<vector<int>> &g)
{
    int m = II, s = 0;
    vector<int> p(g.size(), 0);
    for (int i = 0; i < m; i++) {
        int u = II;
        if (lvl[u] > lvl[s])
            s = u;
        p[u] = 1;
    }

    auto dfs = [&](auto &&dfs, int u, int par) -> int {
        int res = 0, lower = 0;
        for (int &v : g[u])
            if (v != par) {
                res += dfs(dfs, v, u);
                lower |= p[v];
            }
        p[u] |= lower;
        return p[u] && !lower ? 1 : res;
    };
    return dfs(dfs, s, 0) == 1;
}

int main()
{
    fast;
    int n = II;
    vector<vector<int>> g(n + 1);
    for (int i = 1; i < n; i++) {
        int u = II, v = II;
        g[u].push_back(v);
        g[v].push_back(u);
    }

    lvl = vector<int>(n + 1, 0);
    auto dfs = [&](auto &&dfs, int u, int par, int i) -> void {
        lvl[u] = i;
        for (int v : g[u])
            if (v != par)
                dfs(dfs, v, u, i + 1);
    };
    dfs(dfs, 1, 0, 1);

    for (int q = II; q; q--)
        cout << (query(g) ? "YES" : "NO") << "\n";
    return 0;
}