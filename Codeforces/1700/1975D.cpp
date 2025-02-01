#include <bits/stdc++.h>
using namespace std;

#define vec vector<int>
#define vv vector<vec>
#define all(v) v.begin(), v.end()
#define fast ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
#define II ({ int a; cin>>a; a; })
#define pf(x) cout << x << " "
#define pl(x) cout << x << "\n"
#define br cout << "\n"
#define pv(v) {{ for(auto &x : v) pf(x); } br;}

vec path(vv &g, int u, int dest, int par)
{
    if (u == dest)
        return {u};
    for (int &v : g[u])
        if (v != par)
        {
            auto res = path(g, v, dest, u);
            if (res.size()) {
                res.push_back(u);
                return res;
            }
        }
    return {};
}

int solve()
{
    int n = II, a = II - 1, b = II - 1;
    vv g(n);
    for (int i = 1; i < n; i++) {
        int u = II - 1, v = II - 1;
        g[u].push_back(v);
        g[v].push_back(u);
    }

    auto p = path(g, a, b, -1);
    int m = p.size(), maxD = 0;
    a = p[m / 2];

    auto dfs = [&](auto &&dfs, int u, int par, int depth) -> void {
        maxD = max(maxD, depth);
        for (int &v : g[u])
            if (v != par)
                dfs(dfs, v, u, depth + 1);
    };
    dfs(dfs, a, -1, 0);
    return (n - 1) * 2 - maxD + (m / 2);
}

int main()
{
    fast;
    for (int tc = II; tc; tc--)
        pl(solve());
    return 0;
}