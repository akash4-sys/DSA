#include <bits/stdc++.h>
using namespace std;

int dfs(vector<vector<int>> &g, int u, int par)
{
    int ans = 0;
    for (int &v : g[u])
        if (v != par)
            ans |= dfs(g, v, u);
    return !ans;
}

int main()
{
    int n, t, u, v, st, ans = 0;
    cin >> n >> t;
    vector<vector<int>> g(n + 1);
    for (int i = 1; i < n; i++) {
        cin >> u >> v;
        g[u].push_back(v);
        g[v].push_back(u);
    }
    cin >> st;
    cout << (!dfs(g, st, 0) ? "Ron" : "Hermione") << "\n";
    return 0;
}