#include <bits/stdc++.h>
using namespace std;

#define fast ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
#define II ({ int a; cin>>a; a; })

int main()
{
    fast;
    int n = II, m = II, d = 0;
    vector<vector<int>> g(n + 1);
    for (int i = 0; i < m; i++) {
        int u = II, v = II;
        g[u].push_back(v);
        g[v].push_back(u);
    }

    vector<int> par(n + 1, 0), vis(n + 1, 0), ans;
    auto bfs = [&](){
        queue<int> q;
        q.push(1);
        vis[1] = 1;
        while (!q.empty()) {
            d++;
            for (int k = q.size(); k; k--) {
                int u = q.front();
                q.pop();
                if (u == n)
                    return 1;
                for (int &v : g[u])
                    if (!vis[v])
                        q.push(v), par[v] = u, vis[v] = 1;
            }
        }
        return 0;
    };
    
    int res = bfs();
    if (!res) {
        cout << "IMPOSSIBLE\n";
        return 0;
    }

    for (int u = n; u != 0; u = par[u])
        ans.push_back(u);

    cout << d << "\n";
    for (int i = ans.size() - 1; i >= 0; i--)
        cout << ans[i] << " ";
    return 0;
}