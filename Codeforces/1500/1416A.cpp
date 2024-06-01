#ifdef __INTELLISENSE__
#include "../../headers.h"
#else
#include <bits/stdc++.h>
using namespace std;
#endif

#define fast ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
#define II ({ int a; cin>>a; a; })
#define iv(v) { for(auto &x : v) cin >> x; }

void solve()
{
    int n = II;
    vector<int> v(n + 1, 0), mink(n + 1, 0), ans(n + 1, n + 1);
    for (int i = 1; i <= n; i++) {
        int a = II;
        mink[a] = max(mink[a], i - v[a]);
        v[a] = i;
    }

    for (int a = 1; a <= n; a++)
    {
        mink[a] = max(mink[a], n - v[a] + 1);
        if (mink[a] && ans[mink[a]] == n + 1)
            ans[mink[a]] = a;
    }
    
    for (int i = 1, p = -1; i <= n; i++) {
        if (ans[i] != n + 1)
            p = p == -1 ? ans[i] : min(p, ans[i]);
        cout << p << " ";
    }
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