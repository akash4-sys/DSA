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
    int n = II, pos = -1;
    vector<int> a(n);
    for (int i = 0; i < n; i++) {
        a[i] = II;
        if (a[i] > 0)
            pos = i;
    }

    if (pos == -1) {
        cout << n - 1 << "\n";
        for (int i = n - 2; i >= 0; i--)
            cout << i + 1 << " " << i + 2 << "\n";
        return;
    }

    vector<vector<int>> ans;
    while (a[pos] <= 20)
        ans.push_back({pos + 1, pos + 1}), a[pos] *= 2;
    for (int i = 0; i < n; i++)
        if (a[i] < 0)
            a[i] += a[pos], ans.push_back({i + 1, pos + 1});

    for (int i = 1; i < n; i++)
        ans.push_back({i + 1, i});
    
    cout << ans.size() << "\n";
    for (auto &p : ans)
        cout << p[0] << " " << p[1] << "\n";
}

int main()
{
    fast;
    int tc = II;
    while (tc--)
        solve();
    return 0;
}