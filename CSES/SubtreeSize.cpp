#include <bits/stdc++.h>
using namespace std;

int main()
{
    int n;
    cin >> n;
    vector<vector<int>> g(n + 1);
    for (int i = 2, a; i <= n; i++) {
        cin >> a;
        g[a].push_back(i);
    }

    vector<int> cnt(n + 1, 0);
    auto dfs = [&](auto &&dfs, int u) -> int {
        for (int &v : g[u])
            cnt[u] += dfs(dfs, v);
        return ++cnt[u];
    };

    dfs(dfs, 1);
    for (int i = 1; i <= n; i++)
        cout << cnt[i] - 1 << " ";
    return 0;
}