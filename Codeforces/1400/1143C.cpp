#ifdef __INTELLISENSE__
#include "../../headers.h"
#else
#include <bits/stdc++.h>
using namespace std;
#endif

#define fast ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
#define II ({ int a; cin>>a; a; })

int main()
{
    fast;
    int n = II;
    vector<int> c(n, 0), par(n, 0), ans;
    vector<vector<int>> g(n + 1);
    for (int i = 0; i < n; i++) {
        par[i] = II - 1;
        c[i] = II;
        if (par[i] != -2)
            g[par[i]].push_back(i);
    }

    for (int i = 0; i < n; i++)
        if (c[i])
        {
            int flag = 1;
            for (int u : g[i])
                flag *= c[u];
            if (flag)
                ans.push_back(i + 1);
        }
    
    if (ans.empty()) {
        cout << -1;
        return 0;
    }

    for (int x : ans)
        cout << x << " ";
    return 0;
}