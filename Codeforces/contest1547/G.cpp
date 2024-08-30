#include <bits/stdc++.h>
using namespace std;

#define fast ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
#define II ({ int a; cin >> a; a;})

// Simple idea but complicated implementation

int n, m;
vector<vector<int>> g, groups, grpCol;
vector<int> col, ans;

void initialize()
{
    n = II, m = II;
    g.clear(), g.resize(n);
    groups.clear(), groups.resize(2);
    grpCol = vector(2, vector<int>(n, 0));
    col.assign(n, 0), ans.assign(n, 0);
    for (int i = 0; i < m; i++)
        g[II - 1].push_back(II - 1);
}

bool findCycles(int u, vector<int> &color, bool createGroup = 1)
{
    color[u] = 1;
    for(int v : g[u])
        if (!color[v])
            findCycles(v, color, createGroup);
        else if (createGroup)
            groups[color[v] - 1].push_back(v);
    color[u] = 2;
    return 0;
}

void solve()
{
    initialize();
    findCycles(0, col);
    for (int i = 0; i < 2; i++)
        for (auto &u : groups[i])
            findCycles(u, grpCol[i], 0);
    
    for (int i = 0; i < n; i++) {
        int ans = 0;
        if (col[i]) {
            ans = 1;
            if (grpCol[0][i])
                ans = -1;
            else if (grpCol[1][i])
                ans = 2;
        }
        cout << ans << " ";
    }
    cout << endl;
}

int main()
{
    fast;
    for (int tc = II; tc; tc--)
        solve();
    return 0;
}