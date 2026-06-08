#include <bits/stdc++.h>
using namespace std;

int main()
{
    int n;
    cin >> n;
    vector<vector<int>> g(n + 1);
    for (int i = 0; i < n - 1; i++) {
        int u, v;
        cin >> u >> v;
        g[u].push_back(i);
        g[v].push_back(i);
    }

    int flag = 0;
    vector<int> ans(n - 1, -1);
    for (int u = 1; u <= n; u++)
        if (g[u].size() >= 3) {
            for (int i = 0; i < 3; i++)
                ans[g[u][i]] = i;
            flag = 1;
            break;
        }
    
    for (int i = 0, j = 3; i < n - 1; i++)
        cout << (ans[i] == -1 ? j++ : ans[i]) << "\n";
    return 0;
}