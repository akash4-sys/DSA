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
    int n = II, mx = 0, ans = 0;
    vector<int> a(n + 1), pos(n + 1, 0);
    for (int i = 1; i <= n; i++)
        a[i] = II;
    for (int i = 1; i <= n; i++)
        pos[II] = i;

    for (int i = 1; i <= n; i++)
        if (mx < pos[a[i]])
            mx = pos[a[i]];
        else
            ans++;
    cout << ans;
    return 0;
}