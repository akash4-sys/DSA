#include <bits/stdc++.h>
using namespace std;
#define II ({ int a; cin>>a; a; })

// @ KOSARAJU Algorithm

int main()
{
    int n = II, m = II;
    vector<vector<int>> g(n), rg(n);
    while (m--) {
        int u = II - 1, v = II - 1;
        g[u].push_back(v);
        rg[v].push_back(u);
    }
    
    vector<int> col(n, 0), nodes;
    auto dfs = [&](auto &&dfs, int u) -> void {
        col[u] = 1;
        for (int v : g[u])
            if (!col[v])
                dfs(dfs, v);
        nodes.push_back(u);
    };
    for (int i = 0; i < n; i++)
        if (!col[i])
            dfs(dfs, i);
    
    auto rdfs = [&](auto &&rdfs, int u, int c) -> void {
        col[u] = c;
        for (int v : rg[u])
            if (!col[v])
                rdfs(rdfs, v, c);
    };
    
    int c = 1;
    col = vector<int>(n, 0);
    while (!nodes.empty()) {
        int u = nodes.back();
        nodes.pop_back();
        if (!col[u])
            rdfs(rdfs, u, c), c++;
    }

    cout << c - 1 << "\n";
    for (int &x : col)
        cout << x << " ";
    return 0;
}