#ifdef __INTELLISENSE__
#include "../../headers.h"
#else
#include <bits/stdc++.h>
using namespace std;
#endif

#define II ({ int a; cin>>a; a; })

int main()
{
    int n = II, trees = 0;
    set<int> st;
    for (int i = 1; i <= n; i++)
    {
        int a = II;
        if (a == i)
            trees++;
        else
            st.insert(a);
    }
    cout << trees + (st.size() / 2);
    return 0;
}

// int main()
// {
//     int n = II, trees = 0;
//     vector<vector<int>> g(n + 1);
//     for (int i = 1; i <= n; i++)
//     {
//         int u = II;
//         g[u].push_back(i);
//         g[i].push_back(u);
//     }

//     vector<int> vis(n + 1, 0);
//     function<void(int)> dfs = [&](int u) -> void
//     {
//         vis[u] = 1;
//         for (int v : g[u])
//             if (!vis[v])
//                 dfs(v);
//     };

//     for (int i = 1; i <= n; i++)
//         if (!vis[i])
//             dfs(i), trees++;
//     cout << trees << endl;
//     return 0;
// }