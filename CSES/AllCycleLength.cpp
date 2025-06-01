// Planets Cycles

#include <bits/stdc++.h>
using namespace std;

int main()
{
    int n;
    cin >> n;
    vector<int> next(n), vis(n, 0), dist(n, 0);
    for (int &u : next)
        cin >> u, u--;
    
    int steps = 0;
    queue<int> path;
    auto dfs = [&](auto &&dfs, int u) -> int {
        path.push(u);
        if (vis[u]) {
            steps += dist[u];
            return u;
        }

        vis[u] = 1;
        steps++;
        return dfs(dfs, next[u]);
    };

    for (int i = 0; i < n; i++)
        if (!vis[i]) {
            steps = 0;
            int v = dfs(dfs, i), dec = 1;
            while (!path.empty()) {
                int u = path.front();
                path.pop();
                if (u == v) dec = 0;
                dist[u] = steps;
                steps -= dec;
            }
        }
    
    for (int &d : dist)
        cout << d << " ";
    return 0;
}