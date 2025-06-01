#include <bits/stdc++.h>
using namespace std;

#define II ({ int a; cin>>a ; a; })
#define fast ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);

vector<vector<int>> g;
vector<int> path;

void dfs(int u) {
    while (g[u].size()) {
        int v = g[u].back();
        g[u].pop_back();
        dfs(v);
    }
    path.push_back(u);
}

int main()
{
    fast;
    int n = II, m = II;
    g.resize(n);
    vector<int> deg(n, 0);
    for (int i = 0; i < m; i++) {
        int u = II - 1, v = II - 1;
        g[u].push_back(v);
        deg[v]++;
    }

    deg[0]++;                           // for src outdeg - indeg = 0 or 1
    deg[n - 1]--;                       // for dest indeg - outdeg = 0 or 1
    for (int i = 0; i < n; i++)
        if (g[i].size() != deg[i]) {
            cout << "IMPOSSIBLE";
            return 0;
        }
    
    dfs(0);
    if (path.size() != m + 1) {
        cout << "IMPOSSIBLE";
        return 0;
    }
    for (int i = m; i >= 0; i--)
        cout << path[i] + 1 << " ";
    return 0;
}