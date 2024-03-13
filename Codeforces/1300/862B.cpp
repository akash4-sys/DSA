#ifdef __INTELLISENSE__
#include "../../headers.h"
#else
#include <bits/stdc++.h>
using namespace std;
#endif

long long sets[2] = {0};

void dfs(vector<vector<int>> &g, int u, int par, int color)
{
    sets[color]++;
    for (int v : g[u])
        if (v != par)
            dfs(g, v, u, !color);
}

int main()
{
    int n, u, v;
    cin >> n;
    vector<vector<int>> g(n);
    for (int i = 1; i < n; i++) {
        cin >> u >> v;
        g[u - 1].push_back(v - 1);
        g[v - 1].push_back(u - 1);
    }

    dfs(g, 0, -1, 0);
    long long ans = sets[0] * sets[1] - n + 1;
    cout << ans << endl;
    return 0;
}