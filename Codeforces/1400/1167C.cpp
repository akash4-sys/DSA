#ifdef __INTELLISENSE__
#include "../../headers.h"
#else
#include <bits/stdc++.h>
using namespace std;
#endif

#define vec vector<int>
#define vv vector<vec>
#define all(v) v.begin(), v.end()
#define fast ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
#define II ({ int a; cin>>a; a; })

int main()
{
    fast;
    int n = II, m = II;
    vv g(n);
    for (int i = 0; i < m; i++)
    {
        int k = II;
        vec f(k);
        for (int fd : f)
            fd = II - 1;
        
        for (int j = 1; j < k; j++)
            g[f[j - 1]].push_back(f[j]),
            g[f[j]].push_back(f[j - 1]);
    }

    vec vis(n, 0), col_size(n + 1, 0);
    function<int(int, int)> dfs = [&](int u, int col) -> int {
        vis[u] = col;
        int res = 1;
        for (int v : g[u])
            if (!vis[v])
                res += dfs(v, col);
        return res;
    };

    for (int i = 0, col = 1; i < n; i++)
        if (!vis[i])
            col_size[col] = dfs(i, col), col++;
    
    for (int i = 0; i < n; i++)
        cout << col_size[vis[i]] << " ";
    return 0;
}