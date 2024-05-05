#ifdef __INTELLISENSE__
#include "../../headers.h"
#else
#include <bits/stdc++.h>
using namespace std;
#endif

#define fast ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
#define II ({ int a; cin>>a; a; })

void solve()
{
    int n = II;
    vector<int> ans(n + 1, -1), last(n + 1, 0), dist(n + 1, 0);
    for (int i = 1; i <= n; i++)
    {
        int a = II;
        dist[a] = max(dist[a], i - last[a]);
        last[a] = i;
    }

    for (int x = 1; x <= n; x++)
    {
        dist[x] = max(dist[x], n - last[x] + 1);
        for (int i = dist[x]; i <= n && ans[i] == -1; i++)
            ans[i] = x;
    
        cout << "x - " << x << " dist_x -> " << dist[x] << endl;
        for (int i = 1; i <= n; i++)
            cout << ans[i] << " ";
        cout << "\n";
    }
    
    for (int i = 1; i <= n; i++)
        cout << ans[i] << " ";
    cout << "\n";
}

int main()
{
    fast;
    int tc = II;
    while (tc--)
        solve();
    return 0;
}