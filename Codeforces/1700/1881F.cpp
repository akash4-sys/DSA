

#include <bits/stdc++.h>
using namespace std;

#define fast ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
#define II ({ int a; cin>>a; a; })
#define iv(v) { for(auto &x : v) cin >> x; }

vector<vector<int>> g;

void dfs(vector<int> &d, int u, int par)
{
    for (int &v : g[u])
        if (v != par) {
            d[v] = d[u] + 1;
            dfs(d, v, u);
        }
}

int solve()
{
    int n = II, k = II;
    vector<int> v(k), d(n + 1, 0);
    iv(v);
    g.clear();
    g.resize(n + 1);
    for (int i = 1; i < n; i++) {
        int u = II, c = II;
        g[u].push_back(c);
        g[c].push_back(u);
    }

    int u = v[0];
    dfs(d, u, -1);
    for (int &i : v)
        if (d[i] > d[u])
            u = i;
    
    d.clear();
    d.resize(n + 1);
    dfs(d, u, -1);
    for (int &i : v)
        if (d[i] > d[u])
            u = i;
    return (d[u] + 1) / 2;
}

int main()
{
    fast;
    for (int tc = II; tc; tc--)
        cout << solve() << "\n";
    return 0;
}