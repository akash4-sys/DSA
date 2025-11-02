#include <bits/stdc++.h>
using namespace std;

#define II ({ int a; cin>>a ; a; })
#define pv(v) {{ for(auto &x : v) cout << x << " "; } cout << endl;}

int main()
{
    int n = II, m = n - 1;
    if (n == 1) {
        cout << 1;
        return 0;
    }

    vector<vector<int>> g(n);
    while (m--) {
        int u = II - 1, v = II - 1;
        g[u].push_back(v);
        g[v].push_back(u);
    }

    int centroid = -2;
    auto dfs = [&](auto &&dfs, int u, int par) -> int {
        if (g[u].size() == 1 && g[u][0] == par)
            return 1;

        int cnt = 1, flag = 1;
        for (int &v : g[u])
            if (v != par) {
                int res = dfs(dfs, v, u);
                flag &= (res <= n / 2);
                cnt += res;
            }

        if (flag && n - cnt <= n / 2)
            centroid = u;
        return cnt;
    };

    dfs(dfs, 0, -1);
    cout << centroid + 1;
    return 0;
}