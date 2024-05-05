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
    int n = II, m = II;
    vector<set<int>> g(n + 1);
    for (int i = 0; i < m; i++) {
        int u = II, v = II;
        g[u].insert(v);
        g[v].insert(u);
    }

    vector<int> vis(n + 1, 0);
    priority_queue<int, vector<int>, greater<int>> pq;
    pq.push(1);
    while (!pq.empty())
    {
        int u = pq.top();
        pq.pop();
        if (!vis[u])
        {
            cout << u << " ";
            vis[u] = 1;
            for (int v : g[u])
                if (!vis[v])
                    pq.push(v);
        }
    }
    return 0;
}