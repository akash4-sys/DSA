#ifdef __INTELLISENSE__
#include "../../headers.h"
#else
#include <bits/stdc++.h>
using namespace std;
#endif

#define fast ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
#define II ({ int a; cin >> a; a; })
#define pf(x) cout << x << " "
#define pl(x) cout << x << endl

void solve()
{
    int n = II, x = INT_MIN;
    vector<int> v(n);
    for (int i = 0; i < n; i++)
        v[i] = II;
    for (int i = 0; i < n; i++)
        v[i] -= II, x = max(x, v[i]);
    
    pl(count(v.begin(), v.end(), x));
    for (int i = 0; i < n; i++)
        if (v[i] == x)
            pf(i + 1);
    cout << endl;
}

int main()
{
    fast;
    int tc = II;
    while (tc--)
        solve();
    return 0;
}