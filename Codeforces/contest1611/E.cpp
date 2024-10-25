#include <bits/stdc++.h>
using namespace std;

#define fast ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
#define II ({ int a; cin>>a; a; })

bool solve()
{
    int n = II, k = II;
    vector<int> col(n, 0);
    queue<int> q;
    while (k--) {
        int u = II - 1;
        col[u] = 2;
        q.push(u);
    }
    
    vector<vector<int>> g(n);
    for (int i = 1; i < n; i++) {
        int u = II - 1, v = II - 1;
        g[u].push_back(v);
        g[v].push_back(u);
    }

    col[0] = 1;
    q.push(0);
    while (!q.empty()) {
        int u = q.front();
        q.pop();
        for (int v : g[u])
            if (!col[v])
                col[v] = col[u], q.push(v);
    }

    for (int u = 1; u < n; u++)
        if (col[u] == 1 && g[u].size() == 1)
            return 1;
    return 0;
}

int main()
{
    fast;
    for (int tc = II; tc; tc--)
        cout << (solve() ? "YES" : "NO") << "\n";
    return 0;
}